/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> ans;
    int s; // start_index
    int len = arr.size();
    if (arr[0] >= x)
      s = 0;
    else {
      if (arr[len - 1] <= x)
        s = len - k;
      else {

        int l = 0, r = len - 1;
        while (l < r) {
          // check [l, l+1]
          int m = l + (r - l) / 2;
          if (arr[m] >= x) {
            r = m;
          } else {
            // new range[m+1, r]
            l = m + 1;
          }
        }
        int have = 0;
        int left2 = l - 1;
        int right2 = l;
        s = l; // init s = l;
        while (have < k) {
          if ((x - arr[left2]) <= (arr[right2] - x)) {
            s = left2--;
          } else {
            right2++;
          }
          have++;
          //check bound condition
          if (left2 < 0) {
            s = 0;
            break;
          }
          if (right2 >= len) {
            s = len - k;
            break;
          }
        }
      }
    }
    for (int i = s; i < s + k; i++)
      ans.push_back(arr[i]);

    return ans;
  }
};
// @lc code=end
