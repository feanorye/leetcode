#include <algorithm>
#include <functional>
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
using std::queue;
using std::string;
using std::vector;
struct cor {
  int x;
  int y;
  cor(int _x, int _y) : x(_x), y(_y) {}
};
class Solution {
public:
  // bfs
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<cor> q;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          q.emplace(i, j);
        }
      }
    }

    cor e(-1, -1);
    while (!q.empty()) {
      e = q.front();
      q.pop();
      for (auto d : dir) {
        int nx = e.x + d[0], ny = e.y + d[1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || mat[nx][ny] == 0 || ans[nx][ny] != 0)
          continue;
        ans[nx][ny] = ans[e.x][e.y] + 1;
        q.emplace(nx, ny);
      }
    }
    return ans;
  }
};
void printl(vector<vector<int>> &mat) {
  int m = mat.size(), n = mat[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}
int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  vector<vector<int>> res = sol.updateMatrix(ex1);
  printl(res);
  return 0;
}