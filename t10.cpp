#include <functional>
#include <future>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>
using std::async;
using std::cout;
using std::endl;
using std::future;
using std::stack;
using std::thread;
using std::vector;
/*
  @return: 2 times of a
  @_a: param to multiply
*/
int fp(int a) { return a * 2; }
int main() {
  std::promise<int> prom;
  auto f = prom.get_future();
  thread t{[](std::promise<int> pm) {
             std::this_thread::sleep_for(std::chrono::seconds(2));
             pm.set_value(12);
           },
           std::move(prom)};
  cout << f.get() << " == result\n";
  t.join();
  cout << "\n#" << std::this_thread::get_id() << " thread of main\n";
  auto ay = std::async(
      std::launch::async,
      [](int a, int b) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "\n#" << std::this_thread::get_id() << " thread of launch\n";
        return a + b;
      },
      12, 3);
  cout << "async: " << ay.get() << endl;
  int x = 111;
  cout << "before: " << x << endl;
  auto ax = std::async(
      std::launch::deferred,
      [](int &a) {
        cout << "\n#" << std::this_thread::get_id() << " thread of defer\n";
        return a++;
      },
      std::ref(x));
  cout << "before get: " << x << endl;
  cout << ax.get() << "after get: " << x << endl;
  return 0;
}