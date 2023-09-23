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
  /*
    背包问题：dp[i] 需要平方和的最小个数
    dp[4]: 4 = 2*2 -> dp[4] = 1
  */
  int numSquares(int n) {
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++) {
      dp[i] = i; // i可以表示为i个1相加
      for (int j = 1; i - j * j >= 0; j++) {
        // i = dp[i-j*j] + j*j
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

int main() {
  Solution sol;
  printInt("ans: 3 -- ", sol.numSquares(12));
  return 0;
}