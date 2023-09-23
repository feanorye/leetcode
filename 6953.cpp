#include "listnode.h"
#include <algorithm>
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

class Solution {
public:
  bool canSplitArray(vector<int> &nums, int m) {
    // nums = [2, 3, 3, 2, 3], m = 6
    // 分开子数组，要求len == 1 || sum >= 6
    // f[0:n] = f[1:n] || f[0:n-1]
    // len <= 2 true
    // len == 3, if exist sum{} >= m, true
    // [1, 2, 4, 4, 2, 4] 8
    // nums = [2, 1, 3, 1], m = 5
    // {3,4} || {1,3}
    //
    // dp[i,j]: {i,j} sum > m? ans = dp[0,n-1]
    // 小于2的直接返回，否则会污染状态转移
    // dp[i,j] = dp[i-1,j] || dp[i,j-1]
    // dp[i,i] = true
    int n = nums.size();
    vector<int> preSum(n + 1, 0); // 前i个数之和，preSum(i)
    for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    if (n <= 2) {
      return true;
    }
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int len = 2; len < n; len++) {
      for (int i = 0; i + len < n; i++) {
        int j = i + len;
        if (len > 2) {
          dp[i][j] = dp[i + 1][j] || dp[i][j - 1];
          continue;
        }
        int prev = preSum[j] - preSum[i];
        int post = preSum[j + 1] - preSum[i + 1];
        if (prev >= m || post >= m) {
          dp[i][j] = true;
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main() {
  Solution sol;
  vector<int> ex5{2, 2, 1};
  printInt("ans: true -- ", sol.canSplitArray(ex5, 4));
  vector<int> ex4{6, 1, 6, 1, 6, 2, 1, 4};
  printInt("ans: true -- ", sol.canSplitArray(ex4, 8));
  vector<int> ex3{1, 2, 4, 4, 2, 4};
  printInt("true -- ", sol.canSplitArray(ex3, 8));
  vector<int> ex1{2, 3, 3, 2, 3};
  printInt("ans: true -- ", sol.canSplitArray(ex1, 6));
  printInt("ans: false -- ", sol.canSplitArray(ex1, 8));
  vector<int> ex2{2, 1, 3, 4};
  printInt("ans: true -- ", sol.canSplitArray(ex2, 5));
  return 0;
}