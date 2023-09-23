#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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

// 辅助栈做法
class MinStack {
  stack<int> data;
  stack<int> helper;

public:
  MinStack() { helper.push(INT32_MAX); }

  void push(int val) {
    data.push(val);
    if (val < helper.top()) {
      helper.push(val);
    } else {
      helper.push(helper.top());
    }
  }

  void pop() {
    data.pop();
    helper.pop();
  }

  int top() { return data.top(); }

  int getMin() { return helper.top(); }
};

// 不借助多余空间做法
class MinStack2 {
private:
  stack<long long> data;
  long long min_val;

public:
  MinStack2() {}

  void push(int val) {
    if (data.empty()) {
      data.push(0);
      this->min_val = val;
    } else {
      // 指的是和上一位min_val的差值
      long long diff = val - this->min_val;
      data.push(diff);
      if (diff < 0) {
        // min_val一直是当前栈所有数据的最小值
        this->min_val = val;
      }
    }
  }

  void pop() {
    long long diff = data.top();
    data.pop();
    // diff < 0: min_val == old_min_val + data.top()
    //     >= 0: min_val == old_min_val
    if (diff < 0)
      this->min_val = this->min_val - diff;
  }

  int top() {
    // diff < 0: val = min_val
    //      >=0: val = min_val + diff
    long long diff = data.top();
    if (diff < 0)
      return static_cast<int>(this->min_val);
    return static_cast<int>(this->min_val + diff);
  }

  int getMin() { return this->min_val; }
};

int main() {
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  obj->pop();
  int param_5 = obj->getMin();
  cout << "top: " << param_3 << endl;
  cout << "min: -3 --  " << param_4 << endl;
  cout << "min: -2 --  " << param_5 << endl;
  MinStack2 ms;
  ms.push(2147483646);
  ms.push(2147483647);
  cout << "46 -- top: " << ms.top() << " min: " << ms.getMin() << endl;
  ms.pop();
  ms.pop();
  ms.push(2147483647);
  cout << "47 -- " << ms.top() << " \n";
  ms.push(-2147483648);
  cout << "-48 -- top: " << ms.top() << " min: " << ms.getMin() << endl;
  return 0;
}