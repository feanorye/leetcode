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
  int missingNumber(vector<int> &nums) {
    int len = nums.size();
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] == m) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (nums[l] == l)//case: {0, 1, 2}
      return l + 1;
    return l;
  }
}

int main() {
  Solution sol;
}