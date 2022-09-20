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
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int ans = 0;
      int m = grid.size(), n = grid[0].size();
      vector<vector<int>> visited(m,vector<int>(n,-1));
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
          int ret = dfs(grid, visited, i, j, m, n);
          ans = max(ans,ret);
        }
      return ans;
    }
  int dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc,
           int m, int n) {
    if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] == 1 ||
        grid[sr][sc] == 0)
      return 0;
    vis[sr][sc] = 1;
    int area = 1;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      area += dfs(grid, vis, newR, newC, m, n);
    }
    return area;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1 = {{'1', '1', '0', '0', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '1', '0', '0'},
                              {'0', '0', '0', '1', '1'}};
  cout << sol.numIslands(ex1);
  return 0;
}