#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    vector<int> ans;
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto check = [&mat, &visited, &dir, &m, &n](int r, int c) {
      visited[r][c] = -1;
      for (auto e : dir) {
        int nx = r + e[0], ny = c + e[1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
          continue;
        else {
          if (mat[r][c] <= mat[nx][ny]) {
            return false;
          } else {
            visited[nx][ny] = -1;
          }
        }
      }
      return true;
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] == 0) {
          if (check(i, j)) {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 2, 4}, {2, 3, 3}};
  printV(sol.findPeakGrid(ex1),"ans: {3,4}--");
  return 0;
}