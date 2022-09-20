#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
class Solution {
private:
  bool dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc,
           int m, int n) {
    if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] == 1 ||
        grid[sr][sc] == 1)
      return true;
    if ((grid[sr][sc] == 0) &&
        (sr == 0 || sc == 0 || sr == m - 1 || sc == n - 1))
      return false;
    vis[sr][sc] = 1;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool island = true;
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      if (!dfs(grid, vis, newR, newC, m, n))
        island = false;
    }
    return island;
  }

public:
  int closedIsland(vector<vector<int>> &grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0 && visited[i][j] == -1 &&
            dfs(grid, visited, i, j, m, n))
          ans++;
      }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 1, 1, 1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0, 1, 1, 0},
                             {1, 0, 1, 0, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0, 1, 0, 1},
                             {1, 1, 1, 1, 1, 1, 1, 0}};
  cout << sol.closedIsland(ex1) << endl;
  return 0;
}