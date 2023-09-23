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

class KthLargest {
  std::priority_queue<int, vector<int>, std::greater<>> pq;

public:
  KthLargest(int k, vector<int> &nums) {
    for (int n : nums) {
      pq.push(n);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }
    return pq.top();
  }
};

int main() {
  vector<int> ex1{4, 5, 8, 2};
  KthLargest k1(3, ex1);
  printInt("ans: 4 -- ", k1.add(3));
  printInt("ans: 5 -- ", k1.add(5));
  printInt("ans: 5 -- ", k1.add(10));
  printInt("ans: 8 -- ", k1.add(9));
  printInt("ans: 8 -- ", k1.add(4));
  return 0;
}