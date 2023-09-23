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
  // 多重背包
  // f[i,j] = max{ f[i-1, j - kw_i] + kv_i }, 0 <= k <= Ci
  int multi_pack(vector<int> &w, vector<int> &v, vector<int> &cnt,
                 int bag_weight) {
    int n = w.size();
    vector<int> dp(bag_weight + 1, 0);

    // dp[i,j] = max{dp[i-1,j], dp[i, j-w[i]]+v[i]}
    auto CompletePack = [&dp, bag_weight](int w, int v) {
      for (int i = w; i <= bag_weight; i++) {
        dp[i] = max(dp[i], dp[i - w] + v);
      }
    };
    // dp[i,j] = max(dp[i-1,j], dp[i-1, j-w[i]]+v[i]);
    auto ZeroOnePack = [&dp, bag_weight](int w, int v) {
      for (int i = bag_weight; i >= w; i--) {
        dp[i] = max(dp[i], dp[i - w] + v);
      }
    };

    for (int i = 0; i <= n; i++) {
      int M = cnt[i];
      if (w[i] * M > bag_weight) {
        CompletePack(w[i], v[i]);
        continue;
      }
      // M ->{1,2,2^2, ..., 2^k, M-2^k+1}
      int k = 1;
      while (k < M) {
        ZeroOnePack(k * w[i], k * v[i]);
        M -= k;
        k *= 2;
      }
      ZeroOnePack(M, v[i]);
    }
    return dp[bag_weight];
  }
};

int main() {
  Solution sol;
  return 0;
}