#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> sz(n, 0);
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (auto e : roads) {
      sz[e[0]]++;
      sz[e[1]]++;
      graph[e[0]][e[1]] = 1;
      graph[e[1]][e[0]] = 1;
    }
    int ans;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        int count = sz[i] + sz[j];
        if (graph[i][j])
          count--;
        ans = max(ans, count);
      }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
  sol.maximalNetworkRank(8, ex1);
  return 0;
}