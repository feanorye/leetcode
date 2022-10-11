#include <algorithm>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == nums[mid ^ 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
  int singleNonDuplicate2(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    //?? edge condition?
    auto check = [&](int m) {
      if ((m + 1) % 2 == 0) {
        if (m + 1 < n && nums[m] < nums[m + 1])
          return true;
        else
          return false;
      } else {
        if (m + 1 < n && nums[m] == nums[m + 1])
          return true;
        else
          return false;
      }
    };
    while (l < r) {
      int m = l + (r - l) / 2;
      bool flag = check(m);
      if (flag) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return nums[l];
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 2, 2};
  cout << "ans: 1 -- " << sol.singleNonDuplicate(ex1) << endl;
  vector<int> ex2 = {1, 1, 2, 2, 3};
  cout << "ans: 3 -- " << sol.singleNonDuplicate(ex2) << endl;
  vector<int> ex3 = {1};
  cout << "ans: 1 -- " << sol.singleNonDuplicate(ex3) << endl;
  return 0;
}