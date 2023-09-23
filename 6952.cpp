#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
public:
  long long countInterestingSubarrays(vector<int> &nums, int m, int k) {
    // nums[i] % mod == k, we take it as 1, otherwise 0
    // cnt[r] - cnt[l] % mod = k的数量
    // 枚举左右边界超时
    // (cnt[r] - k) % mod = cnt[l] % mod
    // 防止负数 ((cnt[r] - k)% mod + mod) % mod = (cnt[r] % mod - k + mod) % mod
    map<int, int> cnt;
    // note: 为什么=1? 模拟前缀和presum[0] = 0
    cnt[0] = 1;
    int s = 0;
    long long ans = 0;
    for (int x : nums) {
      s += x % m == k;
      ans += cnt[(s - k + m) % m];
      cnt[s % m]++;
    }
    return ans;
  }
  // 超时
  long long countInterestingSubarrays2(vector<int> &nums, int modulo, int k) {
    // [3,1,9,6], 3 , 0
    // [0,1,1,2,3]
    // 假设[0,1,1,1,2,2,3,3,4]
    // 假设l=1, 则cnt = cnt{l} + same{l} * cnt{r}
    // 只有k=0时，才会计算相同l的有效个数, 假设有m个相同, 则 m-1, m-2, 1 =
    // (m-1)*m/2
    int n = nums.size();
    vector<int> preSum(n + 1);
    preSum[0] = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] % modulo == k) {
        preSum[i + 1] = preSum[i] + 1;
      } else {
        preSum[i + 1] = preSum[i];
      }
    }
    long long ans = 0;
    for (int l = 0; l < n;) {
      int l1 = l + 1;
      while (l1 <= n && preSum[l] == preSum[l1]) {
        l1++;
      }
      // presum[l] != presum[l1] || l1 == n
      int zcnt = 0;
      int m = l1 - l;
      if (k == 0 && m > 1) {
        zcnt = (m - 1) * m / 2;
      }
      for (int r = l1; r <= n;) {
        int r1 = r + 1;
        while (r1 <= n && preSum[r] == preSum[r1]) {
          r1++;
        }
        if ((preSum[r] - preSum[l]) % modulo == k) {
          ans += m * (r1 - r);
        }
        r = r1;
      }
      l = l1;
      ans += zcnt;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{3, 1, 2}; // modulo = 3, k = 0
  //  [0,1,1,1]
  printInt("ans: 3 -- ", sol.countInterestingSubarrays(ex2, 3, 0));
  vector<int> ex1{3, 2, 4};
  // [0,1,1,1]
  printInt("ans: 3 -- ", sol.countInterestingSubarrays(ex1, 2, 1));
  return 0;
}