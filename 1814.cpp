#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  int countNicePairs(vector<int> &nums) {
    const int mod = 1e9+7;
    int ans = 0, len = nums.size();
    auto rev = [](int n) {
      int d = 0, sum = 0;
      while (n != 0) {
        d = n % 10;
        sum = (sum * 10) + d;
        n /= 10;
      }
      return sum;
    };
    map<int, int> mem;
    for (int i = 0; i < len; i++) {
      int ret = nums[i] - rev(nums[i]);
      mem[ret]++;
    }
    // same: n * (n-1)
    for (auto [key, cnt] : mem) {
      ans += (cnt * 1L * (cnt - 1) / 2);
      ans %= mod;
    }

    return ans;
  }
};

int main() {
  Solution sol;
  // 1. 13 + 53 = 66, 35+31=66
  // 2. 13+42=55, 24+31=55
  // 3. 10+67=77,
  // 4. 35+42=77, 24+53
  vector<int> ex2 = {13, 10, 35, 24, 76};
  printInt("ans: 4 -- ", sol.countNicePairs(ex2));
  vector<int> ex1 = {42, 11, 1, 97};
  printInt("ans: 2 -- ", sol.countNicePairs(ex1));
  return 0;
}