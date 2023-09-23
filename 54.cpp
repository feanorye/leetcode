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
  // 螺旋矩阵
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rl = 0, cl = 0;
    int rm = matrix.size() - 1, cm = matrix[0].size() - 1;
    vector<int> ans;
    int i = 0, j = 0;
    while (true) {
      for (j = cl; j <= cm; j++)
        ans.push_back(matrix[rl][j]);
      // 改变上边界
      if (++rl > rm)
        break;

      for (i = rl; i <= rm; i++)
        ans.push_back(matrix[i][cm]);
      // 右边界
      if (--cm < cl)
        break;

      for (j = cm; j >= cl; j--)
        ans.push_back(matrix[rm][j]);
      // 下边界
      if (--rm < rl)
        break;
      for (i = rm; i >= rl; i--)
        ans.push_back(matrix[i][cl]);
      // 左边界
      if (++cl > cm)
        break;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  printV(sol.spiralOrder(ex1), "ans: ");
  return 0;
}