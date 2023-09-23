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
  // 类似424
  // 反转k个0后，最长为1的子数组
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int sum = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
      if (nums[r] == 1) {
        sum++;
      }
      while (sum + k < r - l + 1) {
        if (nums[l++] == 1) {
          sum--;
        }
      }
      ans = r - l + 1;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  printInt("ans: 10 -- ", sol.longestOnes(ex2, 3));
  vector<int> ex1{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  printInt("ans: 6 -- ", sol.longestOnes(ex1, 2));
  return 0;
}