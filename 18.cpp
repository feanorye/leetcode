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
  /*
  ** 返回非重复的四数之和
  ** 类似三数之和，先定住前两个数，将其转化为twoSum => 双指针
  */
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    int len = nums.size();
    if (len < 4) {
      return ans;
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 3;) {
      for (int j = i + 1; j <= len - 2;) {
        for (int k = j + 1, l = len - 1; k < l;) {
          int t = target - nums[i] - nums[j];
          // 处理后交给下次循环处理
          // 直接多次循环还得判断出界问题
          if (nums[k] + nums[l] > t) {
            l--;
          } else if (nums[k] + nums[l] < t) {
            k++;
          } else {
            ans.emplace_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
            for (k++; k < l && nums[k] == nums[k - 1]; k++)
              ;
            for (l--; k < l && nums[l] == nums[l + 1]; l--)
              ;
          }
        }
        for (j++; j < len - 2 && nums[j] == nums[j - 1]; j++)
          ;
      }
      for (i++; i < len - 3 && nums[i] == nums[i - 1]; i++)
        ;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{-3, -1, 0, 2, 4, 5};
  printl(sol.fourSum(ex2, 2));
  vector<int> ex1{1, 0, -1, 0, -2, 2};
  printl(sol.fourSum(ex1, 0));
  return 0;
}