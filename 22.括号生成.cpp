/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
      string tmp;
      helper(ans, tmp, 0, 0, n);
      return ans;
    }
    void helper(vector<string> &ans, string tmp, int left, int right, int n) {
      if (tmp.size() == 2 * n) {
        ans.push_back(tmp);
      }
      if (left < n) {
        helper(ans, tmp + '(', left + 1, right, n);
      }
      if (right < left) {
        helper(ans, tmp + ')', left, right + 1, n);
      }
    }
};
// @lc code=end

