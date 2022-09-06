#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
public:
    int search2(vector<int>& nums, int target) {
      int len = nums.size();
      int l = 0, r = len - 1;
      int lend = nums[0];
      int rend = nums[len-1];
      while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < rend) {
          if ((m != 0) && nums[m] < nums[m - 1]) {
            l = m; 
            break;
          }
          r = m;
        } else {
          if ((m != len-1) && nums[m] > nums[m + 1]) {
            l = m + 1;
            break;
          }
          l = m + 1;
        }
      }
      if (target >= lend) {
        r = (l==0)? len - 1: l - 1;
        l = 0;
      } else {
        r = len - 1;
      }
      while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < target) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      if (nums[l] == target)
        return l;
      return -1;
    }
    int search(vector<int>& nums, int target) {
      int len = nums.size();
      int l = 0, r = len - 1;
      int lend = nums[0];
      int rend = nums[len-1];
      while (l < r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) return m;
        if (nums[m] <= rend) {
          if (nums[m] <= target && target <= rend) {
            l = m + 1; 
            continue;
          }
          r = m - 1;
        } else {
          if (nums[0] <= target && target <= nums[m]) {
            r = m - 1 ;
            continue;
          }
          l = m + 1;
        }
      }
      if (nums[l] == target)
        return l;
      return -1;
      
    }
};

int main() {
  Solution sol;
  vector<int> ex1 = {4, 5, 6, 7, 0, 1, 2};
  cout << sol.search(ex1, 0) << endl;
  vector<int> ex2 = {1,3};
  cout << sol.search(ex2, 3) << endl;
  cout << sol.search(ex2, 0) << endl;
}