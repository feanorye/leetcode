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
public:
  vector<int> searchRange2(vector<int> &nums, int target) {
    vector<int> ans;
    int len = nums.size();
    int l = 0, r = len - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else if (nums[m] > target) {
        r = m - 1;
      } else {
        l = m;
        r = m;
      }
    }
    if (len > 0 && nums[l] == target) {
      while (l > 0 && nums[--l] == target)
        ;
      while (r < (len - 1) && nums[++r] == target)
        ;
      if (nums[l] != target)
        l++;
      if (nums[r] != target)
        r--;
      ans.push_back(l);
      ans.push_back(r);
    } else {
      ans.push_back(-1);
      ans.push_back(-1);
    }
    return ans;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans;
    int len = nums.size();
    int l = 0, r = len - 1;
    while (l <= r) { // handle l = r = target
      int m = l + (r - l) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (len == 0 || r > len - 1 || nums[r + 1] != target) {
      ans.push_back(-1);
      ans.push_back(-1);
    } else {
      ans.push_back(r + 1);
      while (r < len-1) {
        if (nums[++r] != target)
          break;
      }
      if (nums[r] != target)
        r--;
      ans.push_back(r);
    }
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> ex5 = {2,2};
  sol.searchRange(ex5, 3);
  vector<int> ex4 = {1};
  sol.searchRange(ex4, 1);
  vector<int> ex3 = {5, 7, 7, 8, 8, 10};
  sol.searchRange(ex3, 8);
  sol.searchRange(ex3, 0);
  vector<int> ex1 = {};
  sol.searchRange(ex1, 0);
  vector<int> ex2 = {1, 2, 3, 3, 4};
  sol.searchRange(ex2, 3);
}