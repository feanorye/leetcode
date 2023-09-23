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
  // todo: finish
  int combinationSum4(vector<int> &nums, int target) {
    // dp[i,j] 前i项组合为 target = j 的组合数
    // dp[i,j] = sum{dp[i-1, j-k*n[i]]}, 0<=k*n[i]<=j
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    return dp[target];
  }
};

int main() {
  Solution sol;
  vector<int> ex1{1, 2, 3};
  // {1,1,1,1}
  // {1,1,2},{1,2,1}, {2,1,1}
  // {2,2},{1,3}, {3,1}
  printInt("ans: 7 -- ", sol.combinationSum4(ex1, 4));
  return 0;
}