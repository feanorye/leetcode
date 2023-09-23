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
  /*
    元素为1的最大矩形：单调栈+前缀和
    sum[i,j]：mat[:i,j-1]连续为1的个数: 则每一行可表示0, s0, s1, ..., sn-1, 0
    从而看做柱形图最大面积
  */
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 2, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          sum[i + 1][j + 1] = sum[i][j + 1] + 1;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      stack<int> st;
      // sum: 0, s0, s1, ..., sn, 0
      for (int j = 0; j <= n + 1; j++) {
        while (!st.empty() && sum[i][j] < sum[i][st.top()]) {
          int h = sum[i][st.top()];
          st.pop();
          int w = j - st.top() - 1;
          ans = max(ans, h * w);
        }
        st.push(j);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1{{'1', '0', '1', '0', '0'},
                           {'1', '0', '1', '1', '1'},
                           {'1', '1', '1', '1', '1'},
                           {'1', '0', '0', '1', '0'}};
  printInt("ans: 6 -- ", sol.maximalRectangle(ex1));
  return 0;
}