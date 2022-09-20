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
  // Count of prefix[] <= x
  private:
  int getCnt(vector<int> &prefix, int x, int n) {
    int res = 0;
    // j:[,n], i[:,n-1]
    for (int i = 0, j = 1; i <= n; i++) {
      while (j <= n && prefix[j] - prefix[i] <= x)
        j++;
      res += j - i - 1;
    }
    return res;
  }
  // Find val satisfy Count(e <=val) == pos
  int getVal(vector<int> &prefix, int pos, int n) {
    int left = prefix[0], right = prefix[n];
    while (left < right) {
      int m = left + (right - left) / 2;
      int cnt = getCnt(prefix, m, n);
      // < : [m+1, right]
      // = : [m]
      // > : [left, m]
      if (cnt < pos) {
        left = m + 1;
      } else {
        right = m;
      }
    }
    return left;
  }
  // sum of first $pos of prefix
  long sumF(vector<int> &nums, int n, int pos, vector<int> &prefix,
           vector<int> &pre_prefix) {
    // find 1st sum(prefix) >= pos
    int val = getVal(prefix, pos, n);
    //处理溢出
    long res = 0, cnt = 0;
    for (int i = 0, j = 1; i < n; i++) {
      while (j <= n && prefix[j] - prefix[i] < val)
        j++;
      // 溢出
      res += pre_prefix[j-1] - pre_prefix[i] - (j - i - 1) * prefix[i];
      cnt += j - i - 1;
    }
    return (res + (pos - cnt) * val) % (long)(1e9 + 7);
  }

public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> prefix(n + 1, 0);
    vector<int> pre_prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefix[i] = prefix[i - 1] + nums[i-1];
    for (int i = 1; i <= n; i++)
      pre_prefix[i] = pre_prefix[i - 1] + prefix[i];
    int ans = sumF(nums, n, right, prefix, pre_prefix) -
              sumF(nums, n, left - 1, prefix, pre_prefix);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1,2,3,4};
  cout << sol.rangeSum(ex1, 4, 1, 5) << endl;
  return 0;
}