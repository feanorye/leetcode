#include "listnode.h"
#include <algorithm>
#include <iostream>
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
  /**
  **  背包问题：计算并返回可以凑成总金额所需的 最少的硬币个数 。
  **  - 如果没有任何一种硬币组合能组成总金额，返回 -1
  */
  int coinChange2(vector<int> &coins, int amount) {
    // dp[n] = \in{i < size} min(dp[n-ci]) + 1
    vector<int> dp(amount + 1, -1);
    std::stable_sort(coins.begin(), coins.end());
    for (int c : coins) {
      if (c > amount) {
        break;
      }
      dp[c] = 1;
    }
    for (int i = 1; i <= amount; i++) {
      if (dp[i] != -1) {
        continue;
      }
      int ans = INT32_MAX;
      for (int c : coins) {
        if (i - c <= 0) {
          break;
        }
        if (dp[i - c] <= 0) {
          continue;
        }
        ans = min(dp[i - c], ans);
      }
      if (ans == INT32_MAX) {
        continue;
      }
      dp[i] = ans + 1;
    }
    return dp[amount];
  }
  int coinChange(vector<int> &coins, int amount) {
    // f[i,v] = max(f[i-1,v], f[i, v-ci] + wi)
    // dp[i,amount] = min(dp[i-1, a], dp[i, a-ci] + 1)
    // 容量：价值综合 价值：1 -> 最小化价值
    // 初始化：
    vector<int> dp(amount + 1, amount + 2);
    dp[0] = 0;
    for (int c : coins) {
      for (int a = c; a <= amount; a++) {
        dp[a] = min(dp[a], dp[a - c] + 1);
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
  // copy from weiwei
  int coinChange5(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] = min(dp[i], dp[i-coin] + 1);
      }
    }
    if (dp[amount] == amount + 1) {
      dp[amount] = -1;
    }
    return dp[amount];
  }
};

int main() {
  Solution sol;
  vector<int> ex3{1};
  printInt("ans: 0 -- ", sol.coinChange(ex3, 0));
  vector<int> ex2{2};
  printInt("ans: -1 -- ", sol.coinChange(ex2, 3));
  vector<int> ex1 = {1, 2, 5};
  printInt("ans: 3 -- ", sol.coinChange(ex1, 11));
  return 0;
}