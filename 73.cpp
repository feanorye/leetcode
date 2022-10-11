#include "listnode.h"
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
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool col_0 = false, row_0 = false;
    // 1st row/col need set 0?
    for (int i = 0; i < m; i++)
      if (matrix[i][0] == 0)
        col_0 = true;
    for (int j = 0; j < n; j++)
      if (matrix[0][j] == 0)
        row_0 = true;
    // use 1st row/col record row/col need reset
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0)
          matrix[0][j] = matrix[i][0] = 0;
      }
    // clear
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
          matrix[i][j] = 0;
      }
    if (col_0)
      for (int i = 0; i < m; i++)
        matrix[i][0] = 0;
    if (row_0)
      for (int j = 0; j < n; j++)
        matrix[0][j] = 0;
  }
  void setZeroes2(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> marked(m, vector<int>(n, 0));
    // mat[][] == 0: not visited
    //            1: row 0
    //            2: col 0
    //            3: row + col 0
    auto paint_row = [&matrix, &marked, n](int row) {
      if (marked[row][0] == 1 || marked[row][0] == 3)
        return;
      for (int i = 0; i < n; i++) {
        if (matrix[row][i] != 0) {
          if (marked[row][i] == 2)
            marked[row][i] = 3;
          else
            marked[row][i] = 1;
          matrix[row][i] = 0;
        }
      }
    };
    auto paint_col = [&matrix, &marked, m](int col) {
      if (marked[0][col] == 2 || marked[0][col] == 3)
        return;
      for (int i = 0; i < m; i++) {
        if (matrix[i][col] != 0) {
          if (marked[i][col] == 1)
            marked[i][col] = 3;
          else
            marked[i][col] = 2;
          matrix[i][col] = 0;
        }
      }
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (marked[i][j] == 0 && matrix[i][j] == 0) {
          paint_row(i);
          paint_col(j);
        }
      }
  }
};
int main() {
  Solution sol;
  vector<vector<int>> ex1 = {
      {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
  sol.setZeroes(ex1);
  printl(ex1);
  return 0;
}