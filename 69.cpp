/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
#include <iostream>
#include <vector>
using std::cout;
class Solution {
public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) {
      return x;
    }
    int l = 0, r = x / 2;
    int k = l;
    while (l < r) {
      // would dead loop if r = l + 1
      int m = l + (r - l + 1) / 2;
      if (m <= x / m) {
        k = m;
        l = m;
      } else {
        r = m - 1;
      }
    }
    return k;
  }
};

  int main() {
    Solution sol;
    std::cout << sol.mySqrt(8);
  }
  // @lc code=end
