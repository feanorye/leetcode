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
private:
  void dfs(vector<vector<int>> &grid, int x, int y, int m,
           queue<pair<int, int>> &q) {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    if (x < 0 || y < 0 || x >= m || y >= m || grid[x][y] == 0 ||
        grid[x][y] == 2) {
      return;
    }
    grid[x][y] = 2;
    q.emplace(x, y);
    for (auto e : dir) {
      int nx = x + e[0], ny = y + e[1];
      dfs(grid, nx, ny, m, q);
    }
  }

public:
  int shortestBridge(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    if (m != n) {
      cout << "ERROR: NOT MATRIX\n";
      return -1;
    }
    bool flag = false;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          dfs(grid, i, j, m, q);
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dist(m, vector<int>(m, 0));
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (auto e : dir) {
        int nx = x + e[0], ny = y + e[1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= m || grid[nx][ny] == 2 || dist[nx][ny]!= 0) {
          continue;
        }
        if (grid[nx][ny] == 1)
          return dist[x][y];
        dist[nx][ny] = dist[x][y] + 1;
        q.emplace(nx, ny);
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{1, 1, 1, 1, 1},
                             {1, 0, 0, 0, 1},
                             {1, 0, 1, 0, 1},
                             {1, 0, 0, 0, 1},
                             {1, 1, 1, 1, 1}};
  
  cout << sol.shortestBridge(ex2) << endl;
  vector<vector<int>> ex1 = {{0, 1}, {1, 0}};
  cout << sol.shortestBridge(ex1) << endl;
  return 0;
}