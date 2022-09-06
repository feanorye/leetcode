/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include <string>
#include <algorithm>
#include <numeric>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
      long s = 0;
      for (auto k : chalk) {
        s += k;
      }
      s = k % s;
      int ans = 0;
      for (int i = 0; i < chalk.size(); i++) {
        s -= chalk[i];
        if (s < 0) {
          ans = i;
          break;
        }
      }
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  vector<int> ex1 = {5, 1, 5};
  sol.chalkReplacer(ex1, 22);
}

