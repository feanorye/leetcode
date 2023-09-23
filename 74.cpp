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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // 二分做法：先找行，再找列
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m - 1;
    // 找到最后一个小于target的行
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      //  <: [m, r]
      // ==: [m]
      //  >: [l,m-1]
      if (matrix[m][0] <= target) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    // 两种可能：1. mat[l,0] <= target
    //          2. mat[l,0] > target: 必须退出false
    if (matrix[l][0] > target)
      return false;
    int row = l;
    l = 0, r = n - 1;
    // 找到target
    while (l < r) {
      int m = l + (r - l) / 2;
      //  <: [m+1, r]
      // ==: [m]
      //  >: [l, m-1]
      if (matrix[row][m] < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return matrix[row][l] == target;
  }
};

int main() {
  Solution sol;
  return 0;
}