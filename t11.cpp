#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using namespace std::chrono;
int main() {
  std::condition_variable cv;
  auto start = std::chrono::high_resolution_clock::now();
  auto f1 = std::async(std::launch::deferred,[]() {
    std::this_thread::sleep_for(std::chrono::seconds{2});
    return 12;
  });
  std::this_thread::sleep_for(std::chrono::seconds{3});
  std::cout << "async: " << f1.get() << endl;
  auto endt = std::chrono::high_resolution_clock::now();
  auto d = std::chrono::duration_cast<std::chrono::milliseconds>(endt - start);
  cout << "total duration: " << d.count() << " ms" << endl;
}