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
  int connectLand(vector<vector<int>> &grid, vector<int> &areas, int r, int c,
                  int m, int n) {
    vector<int> marks;
    auto check = [&grid, &m, &n, &marks](int r, int c) {
      if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
        return false;
      int mark = grid[r][c];
      // check if same island
      for (auto e : marks)
        if (mark == e)
          return false;
      return true;
    };
    int ans = 1;
    if (check(r + 1, c))
      marks.push_back(grid[r + 1][c]);
    if (check(r - 1, c))
      marks.push_back(grid[r - 1][c]);
    if (check(r, c + 1))
      marks.push_back(grid[r][c + 1]);
    if (check(r, c - 1))
      marks.push_back(grid[r][c - 1]);
    for (auto e : marks)
      ans += areas[e];
    return ans;
  }
  int dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc,
          int m, int n, int mark) {
    if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] == 1 ||
        grid[sr][sc] == 0)
      return 0;
    vis[sr][sc] = 1;
    grid[sr][sc] = mark;
    int area = 1;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      area += dfs(grid, vis, newR, newC, m, n, mark);
    }
    return area;
  }

public:
  int largestIsland(vector<vector<int>> &grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));
    //只有一个变量1*1矩阵时，原本大小1*1空间出错
    vector<int> areas(n * m + 2, 0);
    int mark = 2;
    bool allOne = true;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          allOne = false;
          continue;
        }
        if (grid[i][j] == 1) {
          int area = dfs(grid, visited, i, j, m, n, mark);
          areas[mark++] = area;
        }
      }
    if (allOne)
      return n * m;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          int tmp = connectLand(grid, areas, i, j, m, n);
          ans = max(ans,tmp);
        }
      }
    return ans;
  }

};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{1}};
  cout << sol.largestIsland(ex2) << endl;
  vector<vector<int>> ex1 = {{1,1},{0,1}};
  cout << sol.largestIsland(ex1) << endl;
  return 0;
}