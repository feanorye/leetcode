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
private:
  using LL = long long;
  static constexpr LL mod = 1e9 + 7;
  static constexpr LL max_len = 1e5;
  int f[max_len];
  void preTreatment() {
    f[0] = 1;
    for (int i = 1; i < max_len; i++) {
      f[i] = f[i - 1] * 2 % mod;
    }
  }

public:
  // 双指针
  int numSubseq(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> p(n);
    p[0]=1;
    for (int i = 1; i < n; i++) {
      p[i] = p[i - 1] * 2 % mod;
    }
    std::sort(nums.begin(), nums.end());
    // [nums[i],....,nums[v_rside]].sum_of_extream_val <= target
    int sum = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
      if ((nums[l] + nums[r]) > target) {
        r--;
      } else {
        sum = (sum + p[r - l]) % mod;
        l++;
      }
    }
    return sum;
  }
  // 二分查找：20%
  int numSubseq2(vector<int> &nums, int target) {
    preTreatment();
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    // min_v < max_v < target - min_v
    int max_start = target / 2;
    int sum = 0;
    for (int i = 0; i < n && nums[i] <= max_start; i++) {
      int max_v = target - nums[i];
      // min_v == nums[i]
      // [nums[i],....,nums[v_rside]].sum_of_extream_val <= target
      // Find right side of v
      int l = i, r = n - 1;
      while (l < r) {
        int mid = l + (r - l + 1) / 2;
        // <: [m,r]
        // =: m
        // >: [l,m-1]
        if (nums[mid] <= max_v) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      sum = (sum + f[l - i]) % mod;
    }
    return sum;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {5, 2, 4, 1, 7, 6, 8};
  printInt("ans: 127 -- ", sol.numSubseq(ex3, 16));
  vector<int> ex2 = {2, 3, 3, 4, 6, 7};
  printInt("ans: 61 -- ", sol.numSubseq(ex2, 12));

  vector<int> ex1 = {3, 5, 6, 7};
  printInt("ans: 4 -- ", sol.numSubseq(ex1, 9));
  return 0;
}