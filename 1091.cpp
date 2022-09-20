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
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0] == 1)
      return -1;
    int ans = 1;
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0},   {-1, 0},
                     {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    // bfs
    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == n - 1)
          return ans;
        for (auto e : dir) {
          int nx = x + e[0];
          int ny = y + e[1];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

          if (grid[nx][ny] == 0) {
            grid[nx][ny] = 1;
            q.emplace(nx, ny);
          }
        }
      }
      //到达新的一层bfs
      ans++;
    }

    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
  cout << sol.shortestPathBinaryMatrix(ex2) << endl;

  vector<vector<int>> ex1 = {{0, 1}, {1, 0}};
  cout << sol.shortestPathBinaryMatrix(ex1) << endl;
  return 0;
}