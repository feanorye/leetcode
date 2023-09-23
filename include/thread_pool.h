#include <atomic>
#include <deque>
#include <functional>
#include <future>
#include <iostream>
#include <memory>

#include "steal_queue.h"
#include "thread_queue.h"


struct join_threads {
  join_threads(std::vector<std::thread> &) {}
};

using thread_safe::function_wrapper;

class thread_pool {
public:
  // 使用function_wrapper而不是std::function
  thread_safe::thread_safe_queue<function_wrapper> work_queue;
  std::vector<std::thread> threads;
  join_threads joiner;
  std::atomic<bool> done;
  /***********************************************************/

  thread_pool() : done(false), joiner(threads) {
    unsigned const thread_count = std::thread::hardware_concurrency();
    try {
      for (unsigned i = 0; i < thread_count; ++i) {
        threads.push_back(std::thread(&thread_pool::run_pending_task, this));
      }
    } catch (...) {
      done = true;
      throw;
    }
  }

  ~thread_pool() { done = true; }

  // worker thread
  void worker_thread() {
    while (!done) {
      run_pending_task();
    }
  }
  /**
   * @brief This could handle function with different return type
   * @return future<result_type>
   */
  template <typename FunctionType>
  std::future<typename std::result_of<FunctionType()>::type>
  submit(FunctionType f) {
    typedef typename std::result_of<FunctionType()>::type result_type;
    // package_task可以返回future
    std::packaged_task<result_type()> task(std::move(f));
    std::future<result_type> res(task.get_future());
    work_queue.push_back(std::move(task));
    return res;
  }

  // rest as before
  void run_pending_task() {
    function_wrapper task{[] { return 0; }};
    // Note: 循环->条件判断
    if (work_queue.try_pop(task)) {
      task.call();
    } else {
      std::this_thread::yield();
    }
  }
};