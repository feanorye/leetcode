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
  using PDI = pair<double, int>;
  double Dijkstra(std::unordered_map<int, vector<PDI>> &g, int start, int end) {
    std::unordered_map<int, double> dis; // {node, prob}
    dis[start] = 1;
    std::priority_queue<PDI, vector<PDI>, std::less<>> pq;
    pq.push({1, start});

    while (!pq.empty()) {
      auto [p, v] = pq.top();
      pq.pop();
      if (v == end) {
        return dis[v];
      }
      // visited node have bigger prob
      if (p < dis[v]) {
        continue;
      }

      for (auto [np, nv] : g[v]) {
        if (dis.count(nv) == 0 || dis[v] * np > dis[nv]) {
          // 只在此处进行更新dis
          dis[nv] = dis[v] * np;
          pq.push({dis[v] * np, nv});
        }
      }
    }
    return 0;
  }

public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {
    std::unordered_map<int, vector<PDI>> g;
    for (size_t i = 0; i < edges.size(); i++) {
      int e0 = edges[i][0];
      int e1 = edges[i][1];
      g[e0].push_back({succProb[i], e1});
      g[e1].push_back({succProb[i], e0});
    }
    return Dijkstra(g, start_node, end_node);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> eg1{{0, 1}, {1, 2}, {0, 2}};
  vector<double> pb1{0.5, 0.5, 0.2};
  cout << "ans: 0.25 -- " << sol.maxProbability(3, eg1, pb1, 0, 2);
  return 0;
}