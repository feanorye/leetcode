#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    // BFS
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> growup;
    int count = 0; //好的橘子
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] == 2) {
          growup.emplace(r, c);
        } else if (grid[r][c] == 1) {
          count++;
        }
      }
    }
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int round = 0;
    // 注意[[0]]
    while (count > 0 && !growup.empty()) {
      int gs = growup.size();
      for (int i = 0; i < gs; i++) {
        auto [r, c] = growup.front();
        growup.pop();
        for (auto d : dir) {
          int nr = r + d[0], nc = c + d[1];
          if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == 0 ||
              grid[nr][nc] == 2)
            continue;
          count--;
          grid[nr][nc] = 2;
          growup.emplace(nr, nc);
        }
      }
      round++;
    }
    return count == 0 ? round : -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{0}};
  printInt("ans: 0 -- ", sol.orangesRotting(ex2));
  vector<vector<int>> ex1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  printInt("ans: 4 -- ", sol.orangesRotting(ex1));
  return 0;
}