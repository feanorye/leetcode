#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
  void dfs(vector<vector<int>> &grid, vector<vector<int16_t>> &visited, int i,
           int j, int step) {
    if (visited[i][j] > -1 && visited[i][j] < step)
      return;
    visited[i][j] = step;
    int m = grid.size(), n = grid[0].size();
    int c = min(j + grid[i][j], n - 1);
    int r = min(i + grid[i][j], m - 1);
    for (int d0 = j + 1; d0 <= c; d0++) {
      dfs(grid, visited, i, d0, step + 1);
    }
    for (int d1 = i + 1; d1 <= r; d1++) {
      dfs(grid, visited, d1, j, step + 1);
    }
  }
  int minimumVisitedCells2(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int16_t>> visited(m, vector<int16_t>(n, -1));
    dfs(grid, visited, 0, 0, 1);
    return visited[m - 1][n - 1];
  }
  int minimumVisitedCells(vector<vector<int>> &grid) {
    //  令f[i,j]表示：从（i,j)出发，到达右下角需要的最小步数
    //  f[i,j] = 1. min(f[k,j] for k in range(i+1, g+i)) ->列单调栈
    //           2. min(f[i,k] for k in range(j+1, g+j)) ->行单调栈
    // 单调栈：当i,j逆向求值时，如果(i,j)下的步数小于i+x行或者j+x列，会导致
    //        i+x行或者j+x列失效，所以应该维护(i,m)行之间、(j,n)列之间的步数
    //        ，(i,j)的步数取代栈中更大值，留下更小值，从而栈中值 小->大
    int m = grid.size(), n = grid[0].size(), steps;
    // [step, rows] ：行往下移动存在范围
    vector<pair<int, int>> cols[n];
    for (int r = m - 1; r >= 0; r--) {
      // [steps, col]: 列往右移动存在范围
      vector<pair<int, int>> row;
      for (int c = n - 1; c >= 0; c--) {
        // 每次都需要设为最大值，否则不能表示不可达
        steps = INT32_MAX;
        int g = grid[r][c];
        auto &col = cols[c];
        if (r == m - 1 && c == n - 1) {
          steps = 0;
        } else {
          auto it = std::lower_bound(
              row.begin(), row.end(), c + g,
              [](const auto &a, const int b) { return a.second > b; });
          if (it != row.end())
            steps = min(steps, it->first);
          it = std::lower_bound(
              col.begin(), col.end(), r + g,
              [](const auto &a, const int b) { return a.second > b; });
          if (it != col.end())
            steps = min(steps, it->first);
        }
        // 不可达无须记录
        if (steps == INT32_MAX) {
          continue;
        }
        // 存储(i,j)需要的步数
        steps++;
        while (!col.empty() && steps <= col.back().first) {
          col.pop_back();
        }
        col.emplace_back(steps, r);
        while (!row.empty() && steps <= row.back().first) {
          row.pop_back();
        }
        row.emplace_back(steps, c);
      }
    }
    // 不能使用cols栈进行判断，如果不可达不会入栈
    return steps == INT32_MAX ? -1 : steps;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex3 = {
      {6, 4, 8}, {7, 3, 2}, {2, 1, 11}, {8, 13, 12}, {4, 3, 0}};
  printInt("ans: 3 -- ", sol.minimumVisitedCells(ex3));
  vector<vector<int>> ex2 = {{2, 1, 0}, {1, 0, 0}};
  printInt("ans: -1 -- ", sol.minimumVisitedCells(ex2));
  vector<vector<int>> ex1 = {
      {3, 4, 2, 1}, {4, 2, 3, 1}, {2, 1, 0, 0}, {2, 4, 0, 0}};
  printInt("ans: 4 -- ", sol.minimumVisitedCells(ex1));
  return 0;
}