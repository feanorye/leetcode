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
  /* 戳爆气球：价值 = 左 * 中 * 右，相邻气球会随戳破更新 */
  int maxCoins(vector<int> &nums) {
    /**
     * dp[l,r] [l,r]范围内的最大值， {1, nums, 1}
     * dp[l,r] = max{arr[l] * arr[k] * arr[r] + dp[l,k] + dp[k,r], dp[l,r]}
     */
    int n = nums.size();
    vector<int> cpnum(n + 2);
    cpnum[0] = 1;
    cpnum[n + 1] = 1;
    for (int i = 1; i <= n; i++) {
      cpnum[i] = nums[i - 1];
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int offset = 2; offset < n + 2; offset++) {
      for (int l = 0; l + offset < n + 2; l++) {
        int r = l + offset;
        for (int k = l + 1; k < r; k++) {
          dp[l][r] = max(dp[l][r],
                         dp[l][k] + dp[k][r] + cpnum[l] * cpnum[k] * cpnum[r]);
        }
      }
    }
    return dp[0][n + 1];
  }
};

int main() {
  Solution sol;
  return 0;
}