#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
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
  /*背包问题
    - 0 <= i < j < n
    - -target <= nums[j] - nums[i] <= targe
  */
  int maximumJumps(vector<int> &nums, int target) {
    /*dp
      for i in range(i,j,1)
        if j > i && |nums[j] - nums[i]| <= target:
          dp[j] = max{dp[i] + 1}
    */
    int len = nums.size();
    vector<int> dp(len + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < len; i++) {
      if (dp[i] == -1) {
        continue;
      }
      int step = dp[i] + 1;
      for (int j = i + 1; j < len; j++) {
        if (abs(nums[j] - nums[i]) <= target) {
          dp[j] = max(dp[j], step);
        }
      }
    }
    return dp[len-1];
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {0, 2, 1, 3};
  printInt("ans: -1 -- ", sol.maximumJumps(ex1, 1));
  return 0;
}