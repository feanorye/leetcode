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
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n / 2; c++) {
        int tmp = matrix[r][c];
        matrix[r][c] = matrix[r][n - c - 1];
        matrix[r][n - c - 1] = tmp;
      }
    }
  }
};

int main() {
  Solution sol;
  return 0;
}