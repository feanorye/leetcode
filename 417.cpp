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
private:
  // 0: no visited or no route
  // 1: upper route
  // -1: lower route
  // 2: both route
  void bfs(vector<vector<int>> &heights, vector<vector<int>> &route,
           queue<cor> &border, int mark, int m, int n) {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    cor e(-1, -1);
    while (!border.empty()) {
      e = border.front();
      border.pop();
      int oldh = heights[e.x][e.y];

      for (auto d : dir) {
        int nx = e.x + d[0], ny = e.y + d[1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || heights[nx][ny] < oldh ||
            route[nx][ny] == mark || route[nx][ny] == 2)
          continue;
        if (route[nx][ny] == -mark)
          route[nx][ny] = 2;
        else
          route[nx][ny] = mark;
        border.emplace(nx, ny);
      }
    }
  }

public:
  // bfs
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    // route: 1 to upper sea, -1 to lower sea
    vector<vector<int>> route(m, vector<int>(n, 0));
    queue<cor> q;
    auto fix = [&route](int x, int y, int mark) {
      if (route[x][y] == 2)
        return;
      if (route[x][y] == -mark)
        route[x][y] = 2;
      else 
        route[x][y] = mark;
    };
    for (int j = 0; j < n; j++) {
      q.emplace(0, j);
      fix(0, j, 1);
    }
    bfs(heights, route, q, 1, m, n);
    for (int j = 0; j < n; j++) {
      q.emplace(m - 1, j);
      fix(m - 1, j, -1);
    }
    bfs(heights, route, q, -1, m, n);
    for (int i = 0; i < m; i++) {
      q.emplace(i, 0);
      fix(i, 0, 1);
    }
    bfs(heights, route, q, 1, m, n);
    for (int i = 0; i < m; i++) {
      q.emplace(i, n - 1);
      fix(i, n - 1, -1);
    }
    bfs(heights, route, q, -1, m, n);
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (route[i][j] == 2) {
          vector<int> item = {i,j};
          ans.push_back(item);
        }
      }
    return ans;
  }
};

void printl(vector<vector<int>> &heights) {
  int m = heights.size(), n = heights[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << heights[i][j] << "\t";
    }
    cout << endl;
  }
}
int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{8, 7, 7}, {9, 5, 8}, {3, 2, 6}};
  vector<vector<int>> res = sol.pacificAtlantic(ex1);
  printl(res);
  return 0;
}