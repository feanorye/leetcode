#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
  bool search(vector<int> &nums, int target) {
    int len = nums.size();
    int l = 0, r = len - 1;

    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[len - 1]) {
        if (nums[m] < target && target <= nums[len - 1]) {
          l = m + 1;
        } else {
          r = m;
        }
      } else if (nums[m] > nums[0]) {
        if (nums[0] <= target && target <= nums[m])
          r = m;
        else
          l = m + 1;
      } else {
        if (nums[l] == target || nums[r] == target)
          return true;
        l++; //缩小区域
        r--;
      }
    }
    return nums[l] == target;
  }
}

int main() {
  Solution sol;
}