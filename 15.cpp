#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums[0] > 0 || nums[n - 1] < 0)
      return {};
    for (int i = 0; i < n - 2; i++) {
      if (nums[i] > 0)
        break;
      //双指针[j,k]
      for (int j = i + 1, k = n - 1; j < n - 1; j++) {
        int target = -nums[i] - nums[j];
        while (j < k && nums[k] > target)
          k--;
        // 跳出循环可能：1. k <= j
        //              2. nums[k] <= target
        if (j < k && nums[k] == target) {
          vector<int> tmp = {nums[i], nums[j], target};
          ans.emplace_back(tmp);
        }
        while (j < n - 2 && nums[j + 1] == nums[j])
          j++;
      }
      while (i < n - 3 && nums[i + 1] == nums[i])
        i++;
      
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {0, 0, 0, 0};
  printl(sol.threeSum(ex2));
  vector<int> ex1 = {-1, 0, 1, 2, -1, -4};
  printl(sol.threeSum(ex1));
  return 0;
}