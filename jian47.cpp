#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "listnode.h"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::string;
using std::vector;
class Solution {
public:
  // dijkstra
/*   int maxValue2(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> path;
    vector<int> distance(m * n, 0);

    path.emplace_back(0, 0);
    distance[0] = grid[0][0];

    auto max_ele = [&path, &distance, m, n]() {
      int max_val = 0;
      pair<int, int> max_cor;
      for (auto [x, y] : path)
        if (distance[x * n + y] > max_val) {
          max_val = distance[x * n + y];
          max_cor.first = x;
          max_cor.second = y;
        }
      return max_cor;
    };
    int dir[2][2] = {{0, 1}, {1, 0}};
    while (!path.empty()) {
    }
  } */
  int maxValue(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for(int i = 1; i < m; i++)
      grid[i][0] += grid[i - 1][0];
    for(int i = 1; i < n; i++)
      grid[0][i] += grid[0][i - 1];
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] += max(grid[i-1][j],grid[i][j-1]);
      }
    }
    return grid[m-1][n-1];
  }

};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  printl(ex1);
  sol.maxValue(ex1);
  printl(ex1);
  return 0;
}