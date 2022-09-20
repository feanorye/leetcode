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
  void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc,
           int m, int n) {
    // check sr,sc is legal or not
    auto check = [&grid, m, n, &vis](int sr, int sc) {
      if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] == 1 ||
          grid[sr][sc] == 0)
        return false;
      return true;
    };
    if (!check(sr, sc))
      return;
    vis[sr][sc] = 1;

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      dfs(grid, vis, newR, newC, m, n);
    }
    return;
  }

public:
  int numEnclaves(vector<vector<int>> &grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
      dfs(grid, visited, i, 0, m, n);
      dfs(grid, visited, i, n - 1, m, n);
    }
    for (int i = 0; i < n; i++) {
      dfs(grid, visited, 0, i, m, n);
      dfs(grid, visited, m - 1, i, m, n);
    }
    for (int i = 1; i < m - 1; i++)
      for (int j = 1; j < n - 1; j++) {
        if (grid[i][j] == 1 && visited[i][j] == -1)
          ans++;
      }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {
      {1, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 1, 0},
      {0, 1, 0, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 0, 1},
  };
  cout << sol.numEnclaves(ex1) << endl;
  return 0;
}