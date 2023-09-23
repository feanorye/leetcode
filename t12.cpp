#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <memory>
#include <ratio>
#include <thread>
#include <vector>
using std::cout;
using std::endl;
using namespace std::chrono;

int main() {
  
  std::unique_ptr<int> p = std::make_unique<int>(5);
  cout << *p << endl;
  std::vector<int> ex1{5, 3};
  for (auto v : ex1) {
    cout << v << "," ;
  }
  cout << endl;
  std::promise<int> m;
  std::shared_future<int> sf = m.get_future();
  auto f1 = std::async([sf]() -> duration<double, std::milli> {
    auto start = high_resolution_clock::now();
    sf.wait();
    return high_resolution_clock::now() - start;
  });
  auto f2 = std::async([sf]() -> duration<double, std::milli> {
    auto start = high_resolution_clock::now();
    sf.wait();
    return high_resolution_clock::now() - start;
  });
  int a = 12;
  std::this_thread::sleep_for(seconds{1});
  m.set_value(111);
  cout << "f1 take " << f1.get().count() << "f2 take " << f2.get().count()
       << endl;
}