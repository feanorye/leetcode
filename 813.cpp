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

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::vector;

class Solution {
public:
  /*
    DEFINE:
      dp[i, j]: max value of sum of avg of divide [0, i-1] to j parts
    1. dp[i, j]= avg(nums[0:i]), if j == 1
          or= max(dp[x, j-1] + avg(nums[x:i])), if j > 1
    2. i > x >= j - 1     
  */
  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // fix: need double
    vector<double> preSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      // presum of i previous members of vector
      preSum[i] = preSum[i-1] + nums[i-1];
    }
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
    for (int i = 1; i < n + 1; i++) {
      dp[i][1] = preSum[i] / i;
    }
    // dp[n, j] need dp[x, j-1], avg(nums[x:n]): x = (j-1, i)
    // 0 < j <= k, j < i <= n, j-1 <= x < i
    for (int j = 2; j <= k; j++)
      for (int i = j; i <= n; i++)
        for (int x = j - 1; x < i; x++) {
          dp[i][j] = max(dp[i][j], dp[x][j-1] + (preSum[i] - preSum[x])/ (i - x));
        }

    return dp[n][k];
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}