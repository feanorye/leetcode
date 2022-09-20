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
  int maxDistance(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    queue<cor> q;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool hasOcean = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          q.emplace(i, j);
        }else{
            hasOcean = true;
        }
      }
    }
    if (q.empty() || !hasOcean)
      return -1;
    cor e(-1,-1);
    while (!q.empty()) {
      e = q.front();
      q.pop();
      for (auto d : dir) {
        int nx = e.x + d[0];
        int ny = e.y + d[1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 0)
          continue;
        grid[nx][ny] = grid[e.x][e.y] + 1;
        q.emplace(nx,ny);
      }
    }
    if (e.x == -1)
      return -1;
    return grid[e.x][e.y] - 1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  cout << "ans:哈这是 5 -- " << sol.maxDistance(ex1) << endl;
  return 0;
}