#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
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
  /* 数组中添加符号{+,-}, 找到能够让最后结果为target的方案数量
   *  -> sum{ nums[i] } < 1000
   */
  int findTargetSumWays2(vector<int> &nums, int target) {
    /* 类似背包 dp[i,j] 前i个数据能够运算得出j的方法个数
      dp[i,j] = dp[i-1, j-nums[i]] +
                dp[i-1, j+nums[i]]
      初始化：dp[1, nums[i]] = 1, dp[1, -nums[i]] = 1
             -sum <= j - nums[i] <= sum |-> -sum + nums[i] <= j <= sum + nums[i]
             -sum <= j + nums[i] <= sum |-> -sum - nums[i] <= j <= sum - nums[i]
    */
    int sum = 0;
    for (int e : nums) {
      sum += e;
    }
    if (abs(target) > sum) {
      return 0;
    }
    int len = nums.size();
    int off = sum;
    vector<vector<int>> dp(len + 1, vector<int>(sum * 2 + 2, 0));

    dp[1][off + nums[0]] += 1;
    dp[1][off - nums[0]] += 1;
    for (int i = 1; i < len; i++) {
      for (int j = -sum; j <= sum; j++) {
        if (j - nums[i] >= -sum) {
          dp[i + 1][j + off] = dp[i][j - nums[i] + off];
        }
        if (j + nums[i] <= sum) {
          dp[i + 1][j + off] += dp[i][j + nums[i] + off];
        }
      }
    }
    return dp[len][target + off];
  }
  int findTargetSumWays(vector<int> &nums, int target) {
    /** 假设 sum{abs(nums)} = s,
     *  每个公式解中的负值部分为m，则正值部分为 s - m
     *  那么公式解表示为 s - m - m = target, m = (s - t) / 2
     *  可转换为只使用+，即选择元素，结果为m的公式个数
     *    dp[i,j] = dp[i-1, j - nums[i]] + dp[i-1, j]
     *  初始化：j in range(0,m+1), dp[0,0] = 1
     */
    int len = nums.size();
    int s = 0;
    for (auto e : nums) {
      s += abs(e);
    }
    if (abs(s) < target || (s - target) % 2 != 0) {
      return 0;
    }
    int m = (s - target) / 2;
    vector<vector<int>> dp(len + 1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < m + 1; j++) {
        dp[i+1][j] = dp[i][j];
        if (j >= nums[i]) {
          dp[i+1][j] += dp[i][j - nums[i]];
        }
      }
    }
    return dp[len][m];
  }
};

int main() {
  Solution sol;
  vector<int> ex3{1, 999};
  printInt("ans: 1 -- ", sol.findTargetSumWays(ex3, 998));
  vector<int> ex2{0, 0, 0, 0, 0, 0, 0, 0, 1};
  printInt("ans: 256 -- ", sol.findTargetSumWays(ex2, 1));
  vector<int> ex1{1, 1, 1, 1, 1};
  printInt("ans: 5 -- ", sol.findTargetSumWays(ex1, 3));
  return 0;
}