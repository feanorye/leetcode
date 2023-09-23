#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class list {
private:
  ListNode *data;
  ListNode *tail;
  int beg, end;

public:
  list(int b, int e) : beg(b), end(e) {
    data = new ListNode(b);
    ListNode *head = data;
    for (int i = b + 1; i <= e; i++) {
      ListNode *p = new ListNode(i);
      head->next = p;
      head = p;
    }
    tail = head;
  }
  ~list() {
    ListNode *head = data;
    while (head != nullptr) {
      ListNode *son = head->next;
      delete head;
      head = son;
    }
  }
  int head() {
    // 如果没有空余资源，返回-1
    return data->val;
  }
  void remove(int val) {
    ListNode *head = data;
    if (val < this->beg || val > this->end)
      return;
    ListNode *prev = nullptr;
    while (head != nullptr && head->val != -1) {
      if (head->val == val) {
        if (prev == nullptr) {
          data = head->next;
        } else {
          prev->next = head->next;
        }
      } else {
        prev = head;
        head = head->next;
      }
    }
    // 如果该值函数开始前已经申请
    if (head->val == -1 || head == nullptr) {
      return;
    }
    // 重新赋值后加入尾部
    head->val = -1;
    head->next = nullptr;
    tail->next = head;
    tail = head;
  }
  void push(int val) {
    ListNode *head = data;
    // 每个函数都应该检查合法性
    if (val < this->beg || val > this->end)
      return;
    while (head != nullptr && head->val != -1) {
      if (head->val == val)
        return;
      head = head->next;
    }
    // 如果调用函数之前未释放资源
    if (head == nullptr) {
      tail->val = val;
    } else {
      head->val = val;
    }
  }
  void pop() {
    // 如果已经没有空余
    if (data->val == -1)
      return;
    ListNode *head = data;
    data = data->next;
    // 重新赋值将其加入尾部
    head->val = -1;
    head->next = nullptr;
    tail->next = head;
    tail = head;
  }
};

int main() {
  list d(1, 3);
  // return 0;
  d.pop();
  d.pop();
  cout << "ans: 3 -- " << d.head() << endl;
  d.push(1);
  d.push(3);
  d.push(2);
  d.pop();
  d.pop();
  cout << "ans: 2 -- " << d.head() << endl;
  return 0;
}