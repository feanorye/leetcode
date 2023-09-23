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
  /* 长度为n的木棍，切割的代价为当前木棍长度，求切割位置为cuts的最小代价 */
  int minCost(int n, vector<int> &cuts) {
    /**
     *  dp[i,j] = cut[j] - cut[i] + min{dp[i,k] + dp[k,j]}
     *  arr: [0, sort{cuts}, n]
     */
    int m = cuts.size();
    vector<int> arr(m + 2);
    for (int i = 1; i <= m; i++) {
      arr[i] = cuts[i - 1];
    }
    arr[0] = 0;
    arr[m + 1] = n;
    // INT32_MAX / 10
    // todo: 为什么不sort会出错
    std::sort(arr.begin(), arr.end());

    vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
    for (int offs = 2; offs < m + 2; offs++) {
      for (int i = 0; i + offs < m + 2; i++) {
        int j = i + offs;
        int ans = INT32_MAX / 10;
        for (int k = i + 1; k < j; k++) {
          // 若使用dp[i,j]，因为dp[i,j]初始化为0，结果恒为0
          ans = min(ans, dp[i][k] + dp[k][j]);
        }
        dp[i][j] = ans + arr[j] - arr[i];
      }
    }
    return dp[0][m + 1];
  }
};

int main() {
  Solution sol;
  vector<int> ex1{1, 3, 4, 5};
  printInt("ans: 16 -- ", sol.minCost(7, ex1));
  return 0;
}