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
  /*股票问题*/
  int maxProfit(vector<int> &prices) {
    /*
      边界：dp[0][0] = 0, dp[0][1] = - p[i], dp[0][2] = 0
      冷冻期：dp[i][0]= max{dp[i-1, 0], dp[i-1, 2]}
      持有  ：dp[i][1]= max{dp[i-1, 1], dp[i-1, 0]-p[i]}
      卖出  ：dp[i][2]= dp[i-1,1]+p[i]
    */
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    for (int i = 1; i < len; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = dp[i - 1][1] + prices[i];
    }
    return max(dp[len - 1][2], dp[len - 1][0]);
  }
  // 状态机可以减少空间
  int maxProfit2(vector<int> &prices) {
    int len = prices.size();
    int rest = 0;
    int hold = -prices[0];
    int sold = 0;
    int new_rest = 0;

    for (int i = 1; i < len; i++) {
      new_rest = max(rest, sold);
      sold = hold + prices[i];
      hold = max(rest - prices[i], hold);
      // 之前rest被所有依赖
      rest = new_rest;
    }
    return max(rest, sold);
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 2, 3, 0, 2};
  printInt("ans: 3 -- ", sol.maxProfit(ex1));
  return 0;
}