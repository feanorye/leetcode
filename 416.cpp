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
  // todo: 如果存在负数目标，该如何处理？

  /* 返回能否将数组分为总和相等的两个子数组 */
  bool canPartition(vector<int> &nums) {
    /** 每个子数组之和为sum/2
     * 1. 若总和为奇数，必不可分为2个子数组
     * 2. 背包问题：dp[i,j] 前i个数据中是否存在相加之和为j的组合
     *    dp[i,j] = max{dp[i-1, j], dp[i-1, j-nums[i]]}
     *   dp[i,j] 依赖于i-1行的j和j-nums[i], 故从大到小
     */
    long long sum = 0;
    for (int e : nums) {
      sum += e;
    }
    if (sum % 2 != 0) {
      return false;
    }
    long long target = sum / 2;
    int len = nums.size();
    vector<bool> dp(target + 1, false);
    // 初始化条件
    if (nums[0] <= target) {
      dp[nums[0]] = true;
    } else {
      return false;
    }
    for (int i = 1; i < len; i++) {
      // Note: 为什么j--
      // 和i-1，j - nums[i]有关
      for (int j = target; j >= nums[i]; j--) {
        dp[j] = dp[j] || dp[j - nums[i]];
      }
      if (dp[target]) {
        return true;
      }
    }
    return false;
}
};

int main() {
Solution sol;
vector<int> ex2{8, 2, 4};
printInt("ans: false --", sol.canPartition(ex2));
vector<int> ex1{2, 3, 4, 5, 6};
printInt("ans: true -- ", sol.canPartition(ex1));
  return 0;
}