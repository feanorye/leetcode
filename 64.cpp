#include "listnode.h"
#include <algorithm>
#include <functional>
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
  int minPathSum(vector<vector<int>> &grid) {
    int row = grid.size(), col = grid[0].size();
    vector<int> visited(row * col, -1);

    std::pair<int, int> loc{0, 0}, des{row - 1, col - 1};
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>>
        cost;
    int dir[2][2] = {{1, 0}, {0, 1}};
    while (loc != des) {
      int ps = 0;
      while (!cost.empty()) {
        auto [price, pos] = cost.top();
        cost.pop();
        if (visited[pos] > -1) {
          continue;
        }
        visited[pos] = price;
        ps = price;
        loc.first = pos / col;
        loc.second = pos % col;
        break;
      }
      for (auto d : dir) {
        int nx = d[0] + loc.first, ny = d[1] + loc.second;
        if (nx >= row || ny >= col) {
          continue;
        }
        cost.emplace(ps + grid[nx][ny], nx * col + ny);
      }
    }
    if (row * col == 1) {
      return grid[0][0];
    }
    return visited.back() + grid[0][0];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << "ans: 7 -- " << sol.minPathSum(ex1) << endl;
  return 0;
}