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
  // 返回组合数，能够满足和为amount
  int change(int amount, vector<int> &coins) {
    // 完全背包 dp[i,j]: 前i个数据能够组合为j的数量
    // dp[i,j] = sum{dp[i-1, j - k*ci]}, 0 <= k*ci <= j
    //         = dp[i-1, j] + dp[i,j-ci]
    // 0 <= j <= amount
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
      for (int j = c; j <= amount; j++) {
        dp[j] += dp[j - c];
      }
    }
    return dp[amount];
  }
};

int main() {
  Solution sol;
  // 3 = 1 + 1 + 1
  //     2 + 1
  //     1 + 2 重复 => sum{dp[i-ci]}错误
  vector<int> ex1{1, 2, 5};
  printInt("ans: 4 -- ", sol.change(5, ex1));
  return 0;
}