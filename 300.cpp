/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
class Solution {
public:
  // fail:
  // 1,2 is solid to forbid others nums insert
  // so, I think could use {base, maxN, count} record one queue
  // when we counter NUM could be new base(i.e. NUM = base + 1), then change
  // base to NUM. but, this method cannnot solve {0, 1, 3, 4,5,2,3,4,5}
  int lengthOfLIS_fail(vector<int> &nums) {
    struct cnt {
      int base;
      int maxN;
      int count;
    };
    vector<struct cnt> record;
    for (int i = 0; i < nums.size(); i++) {
      bool have = false;
      for (auto &v : record) {
        if (nums[i] > v.maxN) {
          v.count++;
          v.maxN = nums[i];
          have = true;
        }
        if (nums[i] < v.maxN && nums[i] > v.base) {
          v.maxN = nums[i];
          have = true;
        }
        if (nums[i] - v.base == 1) {
          v.base = nums[i];
        }
      }
      if (!have) {
        struct cnt tmp = {nums[i], nums[i], 1};
        record.push_back(tmp);
      }
    }
    int max = 0;
    for (auto v : record) {
      max = max > v.count ? max : v.count;
    }
    return max;
  }
  // dp
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int len = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] > dp[len]) {
        dp[++len] = nums[i];
        continue;
      }
      //find no.1 larger than nums[i]
      if (nums[i] < dp[len]) {
        int l = 0;
        int r = len;
        while (l < r) {
          //check only 2 elem scene.
          int m = l + (r - l) / 2;
          if (dp[m] < nums[i]) {
            l = m + 1;
          } else {
            r = m;
          }
        }
        dp[l] = nums[i];
      }
    }
    return len+1;
  }
};
// @lc code=end
int main() {
  Solution sol;
  vector<int> nums = {0, 1, 0, 8, 9, 10, 5, 6, 7, 2, 3, 4, 5, 6, 7, 8};
  cout << sol.lengthOfLIS(nums) << endl;
  vector<int> nums2 = {10,9,2,5,3,7,101,18};
  cout << sol.lengthOfLIS(nums2) << endl;
}
