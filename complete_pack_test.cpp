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
  /* 完全背包问题 */
  int CompletePack(vector<int> &weights, vector<int> &values, int bag_weights) {
    /**
     * dp[i,j] = max{dp[i-1, j-k*w[i] ] + k*v[i]}, 0<= k*w[i] <= j
     * dp[i,j] = max{dp[i-1,j], dp[i,j-weight[i]] + value[i]}
     * -> dp[i, j-w[i]] = max{dp[i-1, j-w[i]], dp[i,j-2*w[i]]+v[i]}
     * -> dp[i, w[i]] = max{dp[i-1, w[i]], dp[i,0] + v[i]}
     */
    int len = weights.size();
    vector<int> dp(bag_weights + 1, 0);
    for (int i = 0; i < len; i++) {
      for (int j = weights[i]; j <= bag_weights; j++) {
        dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
      }
    }
    return dp[bag_weights];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1{{1, 2, 3}, {5, 15, 30}};
  printInt("ans: 35 -- ", sol.CompletePack(ex1[0], ex1[1], 4));
  return 0;
}