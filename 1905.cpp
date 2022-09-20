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
  bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2,
           vector<vector<int>> &vis, int sr, int sc, int m, int n) {
    // check sr,sc is legal or not
    if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] == 1 ||
        grid2[sr][sc] == 0)
      return true;

    vis[sr][sc] = 1;

    bool ret = true;
    if (grid1[sr][sc] == 0)
      ret = false;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      if (!dfs(grid1, grid2, vis, newR, newC, m, n))
        ret = false;
    }
    return ret;
  }

public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int ans = 0;
    int m = grid1.size(), n = grid1[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (grid2[i][j] == 1 && visited[i][j] == -1 &&
            grid2[i][j] == grid1[i][j])
          if (dfs(grid1, grid2, visited, i, j, m, n))
            ans++;
      }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex3 = {{1, 0, 1, 0, 1},
                             {1, 1, 1, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1},
                             {1, 0, 1, 0, 1}};
  vector<vector<int>> ex4 = {{0, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1},
                             {0, 1, 0, 1, 0},
                             {0, 1, 0, 1, 0},
                             {1, 0, 0, 0, 1}};
  
  cout << sol.countSubIslands(ex3, ex4) << endl;
  vector<vector<int>> ex1 = {{1, 1, 1, 0, 0},
                             {0, 1, 1, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1}};

  vector<vector<int>> ex2 = {{1, 1, 1, 0, 0},
                             {0, 0, 1, 1, 1},
                             {0, 1, 0, 0, 0},
                             {1, 0, 1, 1, 0},
                             {0, 1, 0, 1, 0}};
  cout << sol.countSubIslands(ex1, ex2) << endl;
  return 0;
}