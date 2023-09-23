#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::thread;

class thread_guard {
private:
  // 必须是引用，因为thread禁止复制
  thread &t;

public:
  // exlicit禁止隐式类型转换：单个成员参数构造函数
  explicit thread_guard(thread &t1) : t(t1) {}
  ~thread_guard() {
    if (t.joinable())
      t.join();
  }
  // 复制构造
  thread_guard(thread_guard const &) = delete;
  thread_guard operator=(thread_guard const &) = delete;
};

class scoped_thread {
private:
  thread t;

public:
  explicit scoped_thread(thread _t) : t(std::move(_t)) {
    if (!t.joinable())
      throw std::logic_error("no thread");
  }
  ~scoped_thread() {
    if (t.joinable())
      t.join();
  }
  scoped_thread(scoped_thread const &) = delete;
  scoped_thread operator=(scoped_thread const &)=delete;
};

class stu {
private:
  string name;

public:
  stu(string _name) : name(_name) {}
  void print() { cout << name << " is this instance" << endl; }
};
void hello() { cout << "Hello, concurency" << endl; }
void change_status(int &val) { val = 2; }
void print_s(std::unique_ptr<stu> mem) { mem->print(); }

int main() {
  thread t(hello);
  t.join();
  int val = 123;
  // 默认是右值
  thread t2(change_status, std::ref(val));
  t2.join();
  cout << "format: " << val << endl;
  stu z("zhang");
  // 成员函数第一个参数为this指针
  thread t3(&stu::print, &z);
  t3.join();
  std::unique_ptr<stu> p(new stu("amber"));
  thread t4(print_s, std::move(p));
  t4.join();
  return 0;
}