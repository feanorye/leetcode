#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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

private:
  vector<int> nums;
  // return how many possible $val assemble by nums
  // which is less or equal to $x
  int dp(int x) {
    int ans = 0;
    vector<int> x_bit;
    while (x != 0) {
      x_bit.push_back(x % 10);
      x /= 10;
    }
    // res1: same length as x, 1st == x.1st
    // res2: same length as x, 1st < x.1st, : r *m^(n-1)
    // res3: less than x,                   : 1: m, 2: m*m 3: m^3
    int n = x_bit.size();
    int m = nums.size();
    for (int i = n - 1; i >= 0; i--) {
      // need reassignment
      int r = 0;
      for (; r < m; r++) {
        if (nums[r] > x_bit[i])
          break;
      }
      // 2 result: > || r == m ->[0,n]
      r--;
      if (r < 0 || nums[r] > x_bit[i]) {
        break;
      } else if (nums[r] == x_bit[i]) {
        ans += r * std::pow(m, i);
        // all bit equal
        if (i == 0)
          ans++;
      } else {
        ans += (r + 1) * std::pow(m, i);
        break;
      }
    }
    // res3
    for (int i = 1, last = 1, cur = 1; i < n; i++) {
      cur = last * m;
      ans += cur;
      last = cur;
    }

    return ans;
  }

public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    vector<int> arr;
    for (auto k : digits)
      arr.push_back(std::stoi(k));
    nums = std::move(arr);
    return dp(n);
  }
};

int main() {
  Solution sol;
  vector<string> ex2 = {"3", "4", "5", "6"};
  cout << "ans: 18 -- " << sol.atMostNGivenDigitSet(ex2, 64) << endl;

  vector<string> ex1 = {"1"};
  cout << "ans: 1 -- " << sol.atMostNGivenDigitSet(ex1, 1) << endl;
  return 0;
}