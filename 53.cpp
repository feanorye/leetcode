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
  int maxSubArray(vector<int> &nums) {
    int sum = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum < nums[i])
        sum = nums[i];
      if (sum > max) {
        max = sum;
      }
    }
    return max;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << sol.maxSubArray(ex2);
  vector<int> ex1 = {-1, 2, -2, 3, -1, 4, -5, 6};
  return 0;
}