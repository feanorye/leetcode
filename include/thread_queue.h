#pragma once

#include <algorithm>
#include <condition_variable>
#include <memory>
#include <mutex>
namespace thread_safe {
template <typename T> class thread_safe_queue {
private:
  struct node {
    std::shared_ptr<T> data;
    std::unique_ptr<node> next;
    node(T data_) : data(std::move(data_)) {}
  };
  mutable std::mutex hmut;
  std::unique_ptr<node> head;
  mutable std::mutex tmut;
  node *tail;
  std::condition_variable cond;

  auto GetTail() const -> node * {
    // TODO:为什么加锁呢？->不暴露未完成状态？
    // 防止pop和push同时访问tail
    std::lock_guard<std::mutex> lk(tmut);
    return tail;
  }

  auto PopHead() -> std::shared_ptr<T> {
    // todo: 调用前需要获得head_lock
    std::unique_ptr<node> const old_head = std::move(head);
    head = std::move(old_head->next);
    return old_head->data;
  }
  auto TryPopHead() -> std::shared_ptr<T> {
    // 若GetTail放到lock之前，则在争夺lock时，返回tail可能失效
    std::unique_lock<std::mutex> head_lock(hmut);
    if (head.get() == GetTail()) {
      return {};
    }
    return PopHead();
  }
  // 只在存在值时返回
  auto wait_for_data() -> std::unique_lock<std::mutex> {
    std::unique_lock<std::mutex> head_lock(hmut);
    cond.wait(head_lock, [this] { return head.get != GetTail(); });
    return head_lock;
  }
  auto WaitPopHead() -> std::shared_ptr<T> {
    std::unique_lock<std::mutex> head_lock = wait_for_data();
    return PopHead();
  }

public:
  // 始终存在一个dummy node
  thread_safe_queue() : head(new node), tail(head.get()) {}
  // 拷贝构造函数禁用
  thread_safe_queue(const thread_safe_queue &other) = delete;
  // 赋值构造函数禁用
  thread_safe_queue &operator=(const thread_safe_queue &other) = delete;
  std::shared_ptr<T> try_pop() {
    std::shared_ptr<T> res = PopHead();
    return res;
  }
  bool try_pop(T &val) {
    auto res = WaitPopHead();
    if (res == nullptr)
      return false;
    val = std::move(*res);
    return true;
  }
  void push_back(T new_val) {
    std::unique_ptr<node> p(new node); // new dummy node
    std::shared_ptr<T> newdata = std::make_shared<T>(std::move(new_val));
    node *const new_tail = p.get();
    // lock之后的代码都不会抛出异常
    std::lock_guard<std::mutex> lk(tmut);
    tail->data = std::move(newdata);
    tail->next = std::move(p);
    tail = new_tail;
    cond.notify_one();
  }
  std::shared_ptr<T> wait_and_pop() {
    auto res = WaitPopHead();
    return res;
  }
  void wait_and_pop(T &val) {
    // 此处必定有值
    auto res = WaitPopHead();
    val = std::move(*res);
  }
};
} // namespace thread_safe