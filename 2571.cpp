#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;
using std::stringstream;


class Solution {
public:
  int minOperations(int n) {
    int ans = 0;
    while (n & (n - 1)) {
      int lb = n & (-n);
      if (n & (lb << 1)) {
        n += lb;
      } else {
        n -= lb;
      }
      ans ++;
    }
    return ans;
  }
  // find closest 2^x to n, x is lower bound
  int helper(int n) {
    int l = 0, r = 1e5;
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      // 2^m < n: [m, r]
      //     ==:  [m]
      //    >   : [l, m)
      if (std::pow(2, m) <= n) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}