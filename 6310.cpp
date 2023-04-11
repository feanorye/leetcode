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
  int waysToReachTarget(int target, vector<vector<int>> &types) {
    auto n = types.size();
    const int mod = 1e9 + 7;
    vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));
    int ans = 0;

    // [count, mark]
    auto val = types[0][1];
    for (int t = 1; (val * t) <= target && t <= types[0][0]; t++) {
      dp[0][val * t] = 1;
    }
    for (int i = 0; i < n; i++)
      dp[i][0] = 1;

    // dp[i]: use [0 : i+1] to reach target
    // dp[i][t] = t/v + dp[i-1][t - t/v] + (t/v-1) + dp[i-1][t - t/v + 1] + ...
    for (int i = 1; i < n; i++) {
      if (types[i][1] > target)
        return dp[i - 1][target];
      for (int t = 1; t <= target; t++) {
        int ans = 0, sub = 0;
        int cnt = types[i][0];
        val = types[i][1];
        int m = t % val;
        int c = t / val;
        if (c > cnt) {
          c = cnt;
          m = t - val * c; 
        }
        while (true) {
          if (c < 0 || m > target)
            break;
          ans += dp[i - 1][m];
          c--;
          m += val;
        }
        dp[i][t] = ans;
      }
    }

    return dp[n - 1][target];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{6, 1}, {3, 2}, {2, 3}};
  printInt("asn: 1 -- ", sol.waysToReachTarget(18, ex1));
  printInt("ans: 7 -- ", sol.waysToReachTarget(6, ex1));

  return 0;
}