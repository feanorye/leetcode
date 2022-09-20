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
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (dfs(grid, vis, i, j, m, n))
          ans++;
      }
    return ans;
  }
  bool dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int sr, int sc,
           int m, int n) {
    if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] == 1 ||
        grid[sr][sc] == '0')
      return false;
    vis[sr][sc] = 1;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      dfs(grid, vis, newR, newC, m, n);
    }
    return true;
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