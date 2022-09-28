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
using std::string;
using std::vector;
class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int m = maze.size(), n = maze[0].size();
    // disit matrix
    vector<vector<int>> dist(m, vector<int>(n, -1));
    std::queue<pair<int, int>> q;
    q.emplace(entrance[0], entrance[1]);
    dist[entrance[0]][entrance[1]] = 0;

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (auto e : dir) {
        int nx = x + e[0], ny = y + e[1];
        // out of border && forbidden && visited
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || maze[nx][ny] == '+' ||
            dist[nx][ny] != -1)
          continue;
        dist[nx][ny] = dist[x][y] + 1;
        if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1)
          return dist[nx][ny];
        q.emplace(nx, ny);
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1 = {{'+', '.', '+', '+', '+', '+', '+'},
                              {'+', '.', '+', '.', '.', '.', '+'},
                              {'+', '.', '+', '.', '+', '.', '+'},
                              {'+', '.', '.', '.', '+', '.', '+'},
                              {'+', '+', '+', '+', '+', '.', '+'}};
  vector<int> ent = {0, 1};
  cout << sol.nearestExit(ex1, ent) << endl;
  return 0;
}