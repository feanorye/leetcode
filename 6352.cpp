#include "listnode.h"
#include <algorithm>
#include <cmath>
#include <corecrt.h>
#include <functional>
#include <iostream>
#include <iterator>
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

class Solution {
public:
  // Find 1st elem index which <= val
  int bisearch(const vector<int> &nums, int val, int r) {
    int n = nums.size();
    int left = 0, right = r;
    while (left < right) {
      int m = left + (right - left) / 2;
      // if nums[m] < val: [left, m]
      //            ==   : [m]
      //            >    : (m, right]
      if (nums[m] <= val) {
        right = m;
      } else {
        left = m + 1;
      }
    }
    return left;
  }
  int beautifulSubsetswrong(vector<int> &nums, int k) {
    // 原因：不能保证以完成序列中不出现冲突
    auto n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // 元素均大于0
    // dp[i, 0]: choose ith element
    // dp[i, 1]: except ith element
    dp[0][0] = 1;

    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (int i = 1; i < n; i++) {
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      int idx = bisearch(nums, nums[i] + k, i);
      if (nums[idx] == (nums[i] + k)) {
        dp[i][0] = std::pow(2, i - 1);
      } else {
        dp[i][0] = dp[i][1] + 1;
      }
    }
    return dp[n - 1][0] + dp[n - 1][1];
  }
  int beautifulSubsets(vector<int> &nums, int k) {
    std::unordered_map<int, vector<int>> hash;
    int ans = 1;
    for (auto ele : nums) {
      hash[ele%k].push_back(ele);
    }
    for (auto [_, v] : hash) {
      std::sort(v.begin(), v.end());
      size_t len = v.size();
      // f[i] = f[i-1] * 2^(cnti), if: v[i] != v[i-1]+k
      //      = f[i-1] + f[i-2] * (2^(cnt_i)-1), if: v[i]==v[i-1]+k
      // f[0] = 1 * 2 ^cnt0
      // f[1] = f[0] *2^cnt, if != pre+k
      //      = f[0] + 1*2^(cnt-1)
      int dp1 = 1, dp2 = 1;
      int pre = INT32_MIN;
      for (size_t i0 = 0; i0 < len;) {
        size_t i1 = i0 + 1;
        while (i1 < len && v[i1] == v[i0]) {
          i1++;
        }
        // 1. i1 == len 2.v[i1]!= v[i0]
        int tmp = v[i0] == pre + k ? dp2 : dp1;
        int dp = dp1 + (tmp << (i1 - i0)) - tmp;
        dp2 = dp1;
        dp1 = dp;
        pre = v[i0];
        i0= i1;
      }
      ans *= dp1;
    }
    // remove empty set
    return ans -1;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {7, 6, 5, 4};
  printInt("ans: 11 -- ", sol.beautifulSubsets(ex3, 3));
  vector<int> ex2 = {4, 2, 5, 9, 10, 3};
  printInt("ans: 23 -- ", sol.beautifulSubsets(ex2, 1));

  vector<int> ex1 = {1, 2, 3};
  printInt("ans: 5 -- ", sol.beautifulSubsets(ex1, 2));
  return 0;
}