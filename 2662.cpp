#include "listnode.h"
#include <algorithm>
#include <functional>
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
  // dijkstra
  // 稠密图：不建图直接求
  // 将图中每个路径和起点、终点看做图中节点
  // 定义：dis[node] 到达start起点的最短距离
  // 初始：dis[start] = 0, dis[target] = inf
  //  - 从dis中找到最短路径中未经过的节点作为当前节点
  //  - 更新 nv 相邻节点for v not in visited 路径长度：
  //     - specialRoads {v0, v1, cost}：只关心特殊了路径终点 dis[v1] =
  //     min{dis[v1], dis[v0] + cost}
  //     - 普通节点 dis[v] = min{dis[v], dis[nv] + abs{nv - v}}
  int minimumCost(const vector<int> &start, const vector<int> &target,
                  const vector<vector<int>> &specialRoads) {
    using LL = long long;
    LL t = static_cast<LL>(target[0]) << 32 | target[1];
    std::unordered_map<LL, int> dis = {{(LL)(start[0]) << 32 | start[1], 0},
                                       {t, INT32_MAX}};
    std::set<LL> visited;
    while (true) {
      LL nv = -1;
      int dv = -1;
      for (auto [p, d] : dis) {
        if (visited.count(p) == 0 && (dv == -1 || d < dv)) {
          nv = p;
          dv = d;
        }
      }
      if (nv == t) {
        return dis[t];
      }
      visited.insert(nv);

      int vx = static_cast<int>(nv >> 32);
      int vy = nv & UINT32_MAX;
      dis[t] = min(dis[t], dis[nv] + abs(target[0] - vx) + abs(target[1] - vy));
      for (auto r : specialRoads) {
        LL v1 = static_cast<LL>(r[2]) << 32 | r[3];
        int d = dis[nv] + abs(r[0] - vx) + abs(r[1] - vy) + r[4];
        if (dis.count(v1) == 0 || d < dis[v1]) {
          dis[v1] = d;
        }
      }
    }
  }
};

int main() {
  Solution sol;
  printInt("ans: 5 -- ",
           sol.minimumCost({1, 1}, {4, 5}, {{1, 2, 3, 3, 2}, {3, 4, 4, 5, 1}}));
  return 0;
}