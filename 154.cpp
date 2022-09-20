#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
class Solution {
public:
  int findMin(vector<int> &nums) {
    int len = nums.size();
    int left = 0, right = len - 1;
    while (left < right) {
      int m = left + (right - left) / 2;
      if (nums[m] < nums[right]) {
        right = m;
      } else if(nums[m] > nums[right]) {
        left = m + 1;
      } else {
        right--;
      }
    }
    return nums[left];
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {2, 3, 4, 4, 5, 0, 2};
  cout << sol.findMin(ex1) << endl;
  vector<int> ex2 = {0, 0, 0, 0, 2, 3, 4, 4, 5};
  cout << sol.findMin(ex2) << endl;
  vector<int> ex3 = {3,3,1,3};
  cout << sol.findMin(ex3) << endl;
  return 0;
}