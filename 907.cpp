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
  // 子数组最小值之和: 类似992，贡献法 + 单调栈
  // [3,1,2,4]
  // 3: [3], 1:[1], [3,1],[1,2],[3,1,2],[1,2,4],[3,1,2,4]
  // 2:[2],[2,4] 4:[4]
  // 任意元素对应的子数组数量：left = 小于nums[i]的最近序号， right= 右侧小于等于nums[i]的最近序号
  // 数量 = (i - left) * (right - i)
  // v2: optimize of 3
  int sumSubarrayMins(vector<int> &arr) {
    const int mod = 1e9 + 7;
    int ans = 0, n = arr.size();
    stack<int> st;
    // left[i]: -1 expand to left end
    for (int i = 0; i <= n; i++) {
      int t = (i == n) ? (0) : arr[i];
      // check right bound: [0, n]
      while (!st.empty() && arr[st.top()] > t) {
        int cur = st.top();
        st.pop();
        // check left bound:[-1, n-1]
        int l = (st.empty()) ? -1 : st.top();
        int a = cur - l;
        int b = i - cur;
        ans = (ans + (long long)(a * b) * arr[cur] % mod) % mod;
      }
      st.push(i);
    }
    return ans;
  }
  // 单调栈
  // int[] left:  l[i] first left ele < arr[i]
  // int[] right: r[i] first right ele < arr[i]
  int sumSubarrayMins3(vector<int> &arr) {
    const int mod = 1e9 + 7;
    int ans = 0, n = arr.size();
    stack<int> st;
    // left[i]: -1 expand to left end
    vector<int> left(n, -1), right(n, n);
    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        right[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        left[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }
    for (int i = 0; i < n; i++) {
      long long a = right[i] - i;
      long long b = i - left[i];
      long long sum = (a * b) % mod * arr[i] % mod;
      ans = (ans + sum) % mod;
    }
    return ans;
  }
  // fail: exceed time limit
  int sumSubarrayMins2(vector<int> &arr) {
    const int mod = 1e9 + 7;
    int ans = 0;
    int n = arr.size();
    // dp[i]: min of arr[i, it_j],
    // it_j: iteration
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    ans += dp[0];
    for (int i = 1; i < n; i++) {
      int j = i;
      // initialize dp[i]
      dp[i] = arr[i];
      while (j >= 0) {
        dp[j] = min(dp[j], arr[i]);
        ans = (ans + dp[j]) % mod;
        j--;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {71, 55, 82, 55};
  printInt("ans: 593 -- ", sol.sumSubarrayMins(ex2));
  vector<int> ex1 = {3, 1, 2, 4};
  printInt("ans: 17 -- ", sol.sumSubarrayMins(ex1));
  return 0;
}