/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {

        int left = j + 1;
        int right = n - 1;
        int mid = left;
        int k = j; //满足条件的数据序号
        while (left <= right) {
          mid = (left + right) / 2;

          if (nums[mid] < nums[i] + nums[j]) {
            k = mid;
            left = mid + 1;
          } else {
            right = mid -1;
          }
        }
        ans += k - j;

      }
    }
    return ans;
  }
};
// @lc code=end
