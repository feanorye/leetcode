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
  // 每个元素代表最大跳数，返回能否跳到最后下标
  bool canJump(vector<int> &nums) {
    int len = nums.size();
    vector<int> dp(len, -1);
    dp[len-1] = 1;
    for (int i = len - 2; i >= 0; i--) {
      int succ = 0;
      for (int j = 1; j <= nums[i]; j++) {
        if (dp[i + j] == 1) {
          succ = 1;
          break; 
        }
      }
      dp[i]= succ;
    }
    return dp[0];
  }
};

int main() {
  Solution sol;
  return 0;
}