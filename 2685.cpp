#include "listnode.h"
#include <algorithm>
#include <functional>
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
  // 完全连通图数量：每个节点对都存在边
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n);
    // 建图
    for (auto& v : edges) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }
    vector<int> vis(n, 0);
    int v, e;
    std::function<void(int)> dfs = [&](int i) {
      vis[i] = 1;
      // 边e会统计两次
      e += g[i].size();
      v++;
      for (int j : g[i]) {
        if (!vis[j]) {
          dfs(j);
        }
      }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        e = 0;
        v = 0;
        dfs(i);
        // Select_n^2: n * (n-1) / 2!
        ans += e == v * (v-1);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}