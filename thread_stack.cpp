#include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct empty_stack : std::exception {
  // const: read-only
  // throw(): 不会抛出任何异常
  const char *what() const throw();
};
template <typename T> class threadsafe_stack {
private:
  std::stack<T> data;
  mutable std::mutex m;//mutable可被const函数修改

public:
  threadsafe_stack() {}
  threadsafe_stack(const threadsafe_stack &other) {
    std::lock_guard<std::mutex> lock(other.m);
    data = other.data;
  }
  threadsafe_stack &operator=(const threadsafe_stack &) = delete;
  void push(T val) {
    std::lock_guard<std::mutex> lock(m);
    data.push(std::move(val));
  }
  std::shared_ptr<T> pop() {
    std::lock_guard<std::mutex> lock(m);
    // 弹出前检查是否已空，防止其它线程出栈
    if (data.empty())
      throw empty_stack();
    // 修饰p，p的值不可修改
    std::shared_ptr<T> const p = std::make_shared<T>(std::move(data.top()));
    data.pop();
    return p;
  }
  void pop(T &val) {
    std::lock_guard<std::mutex> lock(m);
    // 弹出前检查是否已空，防止其它线程出栈
    if (data.empty())
      throw empty_stack();
    // 赋值可抛异常
    val = data.top();
    data.pop();
  }
  // const函数默认不可修改成员变量，即read-only function
  // 多线程情境下，empty意义不大，因为调用之后，其他线程可能对容器进行更改
  bool empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
  }
};