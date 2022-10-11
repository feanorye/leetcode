#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::abs;
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
private:
  // find closest $ele to val
  // ret-> min sub val. i.e ([1,4,5], 2), return 1
  int bisearch(vector<int> &nums, int val) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      // <: [m+1,r]
      // =: [m]
      // >: [l,m]
      if (nums[mid] < val) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    // possible res:
    // 1. val < [all]   res = 0:    val < nums[0]
    // 2. [val < res]   res = 0,n-1:  val = nums[0] ||
    //                  nums[i-1] <= val <= nums[i]
    // 3. [all] < val   res = n-1:  nums[n-1] <= val
    cout << "\nval: " << val << " nums[i]: " << nums[low] << " ";
    if (low > 0)
      cout << nums[low - 1];
    int ans = 0;
    ans = abs(nums[low] - val);
    if (low > 0)
      ans = min(abs(nums[low - 1] - val), ans);
    cout << "\t ans: " << ans;
    return ans;
  }

public:
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    static constexpr int mod = 1'000'000'007;
    vector<int> rec(nums1);
    sort(rec.begin(), rec.end());
    int sum = 0, maxn = 0;
    int n = nums1.size();
    for (int i = 0; i < n; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      sum = (sum + diff) % mod;
      int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
      if (j < n) {
        maxn = max(maxn, diff - (rec[j] - nums2[i]));
      }
      if (j > 0) {
        maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
      }
    }
    return (sum - maxn + mod) % mod;
  }

  int minAbsoluteSumDiff2(vector<int> &nums1, vector<int> &nums2) {
    long long mod = (long long)(10e9 + 7);
    vector<int> a1 = nums1;
    sort(a1.begin(), a1.end());
    int n = nums1.size();
    long long sum = 0;
    int max_fix = 0;
    for (int i = 0; i < n; i++) {
      int v = abs(nums1[i] - nums2[i]);
      sum = (sum + v) % mod;
      if (v != 0) {
        int fix = bisearch(a1, nums2[i]);
        fix = v - fix;
        cout << "\tfix: " << fix << endl;
        max_fix = max(max_fix, fix);
      }
    }
    cout << "sum: " << sum << " maxfix : " << max_fix << endl;
    sum = (sum - max_fix + mod) % mod;
    return sum;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {
      38, 48, 73, 55, 25, 47, 45, 62, 15, 34,  51, 20, 76, 78, 38, 91,  69,
      69, 73, 38, 74, 75, 86, 63, 73, 12, 100, 59, 29, 28, 94, 43, 100, 2,
      53, 31, 73, 82, 70, 94, 2,  38, 50, 67,  8,  40, 88, 87, 62, 90,  86,
      33, 86, 26, 84, 52, 63, 80, 56, 56, 56,  47, 12, 50, 12, 59, 52,  7,
      40, 16, 53, 61, 76, 22, 87, 75, 14, 63,  96, 56, 65, 16, 70, 83,  51,
      44, 13, 14, 80, 28, 82, 2,  5,  57, 77,  64, 58, 85, 33, 24};
  vector<int> ex4 = {
      90, 62, 8,   56, 33, 22, 9,  58, 29, 88, 10, 66, 48, 79, 44, 50, 71,
      2,  3,  100, 88, 16, 24, 28, 50, 41, 65, 59, 83, 79, 80, 91, 1,  62,
      13, 37, 86,  53, 43, 49, 17, 82, 27, 17, 10, 89, 40, 82, 41, 2,  48,
      98, 16, 43,  62, 33, 72, 35, 10, 24, 80, 29, 49, 5,  14, 38, 30, 48,
      93, 86, 62,  23, 17, 39, 40, 96, 10, 75, 6,  38, 1,  5,  54, 91, 29,
      36, 62, 73,  51, 92, 89, 88, 74, 91, 87, 34, 49, 56, 33, 67};

  cout << "ans: 3286 -- " << sol.minAbsoluteSumDiff(ex3, ex4) << endl;
  /*   std::sort(ex3.begin(), ex3.end());
    printV(ex3, "ex3: "); */
  /*   vector<int> ex1 = {1, 2, 3};
    cout << "ans: 0 -- " << sol.minAbsoluteSumDiff(ex1, ex1) << endl;
    vector<int> ex2 = {2, 1, 3};
    cout << "ans: 1 -- " << sol.minAbsoluteSumDiff(ex1, ex2) << endl; */
  return 0;
}