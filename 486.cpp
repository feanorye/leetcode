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
  bool predictTheWinner(vector<int> &nums) {
    /** 区间dp- 区间规划- 动态规划
     * dp[i,j]表示区间[i,j]内先手可以取到的净胜分数，即score1 - score2
     * dp[i,j] = max{nums[i] - dp[i+1,j], nums[j] - dp[i,j-1]}
     * 已知dp[i,i] =
     * i，而dp[i,j]依赖dp[i+1,j]和dp[i,j-1],也就是区间长度减1的结果 {5,2,3,6}
     */
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
    }

    for (int len = 1; len < n; len++) {
      for (int i = 0; i < n - len; i++) {
        int j = i + len;
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1] > 0;
  }
};

int main() {
  Solution sol;
  vector<int> ex1{1, 5, 233, 7};
  printInt("ans: true -- ", sol.predictTheWinner(ex1));
  return 0;
}