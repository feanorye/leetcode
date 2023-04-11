#include "listnode.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits.h>
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
  // 将石头堆合并，合并代价为石头数量，每次合并k个
  // [3,2,4,1]
  // [3,6,1] 6
  // [3,7]    7
  // [10]     10
  int mergeStones(vector<int> &stones, int k) {
    // dfs(0,len-1,1) = dfs(0,len-1,k) + preSum[len-0]
    // m<j,否则m+1会大于j
    // dfs(i,j,k) = min( dfs(i,m,1) + dfs(m+1,j,k-1) for m in range(i,j,k-1) )
    // dfs(i,j,1) = dfs(i,j,k) + preSum(i,j+1)
    // 终止条件：dfs[i,i,1] = 0
    size_t len = stones.size();
    if ((len - 1) % (k - 1) != 0) {
      return -1;
    }
    vector<int> preSum(len + 1, 0);
    for (int i = 0; i < len; i++) {
      preSum[i + 1] = preSum[i] + stones[i];
    }
    // preSum[i+1]: nums.sum(0:i+1),前i+1个数之和
    // k+1: dp[i][j][k]才不会失效
    vector<vector<vector<int>>> dp(
        len, vector<vector<int>>(len, vector<int>(k+1, -1)));
    std::function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
      int &res = dp[i][j][p];
      if (res != -1)
        return res;
      if (p == 1) {
        return res = (i == j) ? 0 : dfs(i, j, k) - preSum[i] + preSum[j + 1];
      }
      res = INT_MAX;
      for (int m = i; m < j; m += (k - 1)) {
        res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
      }
      return res;
    };
    return dfs(0, len - 1, 1);
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {3, 1, 2, 4};
  printInt("ans: 19 -- ", sol.mergeStones(ex1, 2));
  return 0;
}