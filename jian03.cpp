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
  int findRepeatNumber(vector<int> &nums) {
    int ans = -1;
    for (int i = 0; i < nums.size();) {
      if (nums[i] == i) {
        // 每次i++都需要判断
        i++;
        continue;
      }
      else if (nums[nums[i]] == nums[i]) {
        return nums[i];
      } else {
        std::swap(nums[i], nums[nums[i]]);
        // swap之后需要重新判断nums[i]是否重复
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {3, 4, 2, 1, 1, 0};
  printInt("ans: 1 -- ", sol.findRepeatNumber(ex1));
  return 0;
}