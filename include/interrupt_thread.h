#include <thread>
namespace thread_safe {
class interrupt_thread {
private:
  std::thread internal_thread;
};
}//namespace thread_safe