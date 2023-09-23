#include "listnode.h"
#include <algorithm>
#include <functional>
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
// 找到中位数
class MedianFinder {
  // 将整段数据分为两个部分，左集和右集
  // 数据总量为偶数：l.size == r.size,     m = (l.top + r.top) / 2
  //          奇数：l.size == r.size + 1, m = l.top
  std::priority_queue<int, vector<int>, std::less<>> l; //大顶堆
  std::priority_queue<int, vector<int>, std::greater<>>r; //小顶堆
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
      // 保持l < r, l.szie \in (r.size, r.size + 1)
      if (l.size() == r.size()) {
        // 保证放入之后l.size = r.size + 1
        if (r.size() == 0) {
          l.push(num);
          return;
        }
        if (num > r.top()) {
          // 直接放入r，会使r.size > l.size
          int tmp = r.top();
          r.pop();
          l.push(tmp);
          r.push(num);
        } else {
          l.push(num);
        }
      } else {
        // 保证l.size == r.size
        if (num < l.top()) {
          // 直接放入l, 会使的l.size == r.size + 2
          int tmp = l.top();
          l.pop();
          r.push(tmp);
          l.push(num);
        } else {
          r.push(num);
        }
      }
    }
    
    double findMedian() {
      if (l.size() == r.size()) {
        return static_cast<double>(l.top() + r.top()) / 2;
      } else {
        return l.top();
      }
    }
};

int main() {
    MedianFinder sol;
    sol.addNum(1);
    sol.addNum(2);
    cout << "ans: 1.5 -- " << sol.findMedian() << endl;
    sol.addNum(3);
    cout << "ans: 2 -- " << sol.findMedian() << endl;
  return 0;
}