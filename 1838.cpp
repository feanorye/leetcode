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
using std::sort;
using std::string;
using std::vector;
class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = 1;
    int cnt = 1;
    for (; r < n; r++) {
      // k - increament
      k -= (r - l) * (nums[r] - nums[r - 1]);
      while (k < 0) {
        k += nums[r] - nums[l];
        l++;
      }
      cnt = max(cnt, r - l + 1);
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {3};
  cout << "ans: 1 -- " << sol.maxFrequency(ex3, 3056) << endl;
  
  vector<int> ex2 = {
      9930, 9923, 9983, 9997, 9934, 9952, 9945, 9914, 9985, 9982, 9970,
      9932, 9985, 9902, 9975, 9990, 9922, 9990, 9994, 9937, 9996, 9964,
      9943, 9963, 9911, 9925, 9935, 9945, 9933, 9916, 9930, 9938, 10000,
      9916, 9911, 9959, 9957, 9907, 9913, 9916, 9993, 9930, 9975, 9924,
      9988, 9923, 9910, 9925, 9977, 9981, 9927, 9930, 9927, 9925, 9923,
      9904, 9928, 9928, 9986, 9903, 9985, 9954, 9938, 9911, 9952, 9974,
      9926, 9920, 9972, 9983, 9973, 9917, 9995, 9973, 9977, 9947, 9936,
      9975, 9954, 9932, 9964, 9972, 9935, 9946, 9966};
  cout << "ans: 73 -- " << sol.maxFrequency(ex2, 3056) << endl;
  vector<int> ex1 = {4, 4, 4};
  cout << "ans: 3 -- " << sol.maxFrequency(ex1, 10) << endl;
  return 0;
}