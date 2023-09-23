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
  // 跳跃游戏2
  int jump(vector<int> &nums) {
    int ans = 0, end = 0, maxPos = 0;
    int len = nums.size();
    for (int i = 0; i < (len - 1); i++) {
      maxPos = max(maxPos, i + nums[i]);
      if (i == end) {
        end = maxPos; //更新下一跳范围
        ans++;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {2, 3, 1, 1, 4};
  printInt("ans: 2 -- ", sol.jump(ex1));
  return 0;
}