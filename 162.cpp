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
using std::vector;
using std::string;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int len = nums.size();
      int l = 0, r = len -1 ;
      while (l < r) {
        int m = l + (r - l) / 2;
        // m > m + 1: [l, m]
        // = :        x
        // < :        [m+1, r]
        if (nums[m] > nums[m + 1]) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      return l;
    }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}