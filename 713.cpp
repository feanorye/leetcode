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
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    // 乘积严格小于k的子数组数目
    // {4,5,2,10,3,3,5}, k = 100
    //
    int n = nums.size();
    int ans = 0;

    int mul = 1;
    // todo: 为什么有的只用看left
    for (int left = 0, right = 0; right < n; right++) {
      int x = nums[right];
      mul *= x;
      while (mul >= k && left < right) {
        mul /= nums[left++];
      }
      if (mul < k) {
        ans += (right - left + 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{1, 2, 3};
  printInt("ans: 0 --", sol.numSubarrayProductLessThanK(ex2, 0));
  vector<int> ex1{10, 5, 2, 6};
  // 10
  // [10, 5], [5]
  // [5, 2], [2]
  // [5,2,6], [2,6], [6]
  printInt("ans: 8-- ", sol.numSubarrayProductLessThanK(ex1, 100));
  return 0;
}