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
  /* 编辑距离：词1转为词2的最小修改次数
    dp[i,j]: min time of word1[:i] -> word2[:j]
    - 边界：
      dp[i,0] = i
      dp[0,j] = j
    - 状态转移：
      if word1[i-1] != word2[j-1]:
        1. modify: dp[i,j] = dp[i-1,j-1] + 1
        2. remove: dp[i,j] = dp[i-1,j]+1
        3. insert: dp[i,j] = dp[i,j-1]+1
  */
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        int ans = min(dp[i - 1][j - 1], dp[i - 1][j]);
        dp[i][j] = min(ans, dp[i][j - 1]) + 1;
        if (word1[i - 1] == word2[j - 1]) {
          // todo: 和题解不一样，检查是否正确
          dp[i][j] = dp[i-1][j-1];
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution sol;
  printInt("ans: 3 -- ", sol.minDistance("horse", "ros"));
  return 0;
}