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
  // 打家劫舍：不可取连续的两个数字==跳过>=2个数字
  int rob(vector<int> &nums) {
    // [2,7,9,3,1]
    // f[0] = 2, f[1] = max(f[0], 7+0)
    // f[2]= max( f[1], f[0]+9 ) = 11
    // f[3] = max(f[2], f[1]+3) = 11
    // f[4] = max(f[3], f[2]+1) = 12
    int len = nums.size();
    if (len < 2)
      return nums[0];
    int f0 = nums[0], f1 = max(nums[0], nums[1]);
    for (int i = 2; i < len; i++) {
      int tmp = max(f1, f0 + nums[i]);
      f0 = f1;
      f1 = tmp;
    }
    return f1;
  }
};

int main() {
  Solution sol;
  vector<int> ex1{2, 7, 9, 3, 1};
  printInt("ans: 12 -- ", sol.rob(ex1));
  return 0;
}