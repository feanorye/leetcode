#include "listnode.h"
#include <algorithm>
#include <deque>
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
using std::deque;
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
  //单调队列
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<long long> presum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }
    int ans = n + 1;
    for (int i = 0; i <= n; i++) {
      while (!dq.empty() && presum[i] - presum[dq.front()] >= k) {
        ans = std::min(ans, i - dq.front());
        dq.pop_front();
      }
      while (!dq.empty() && presum[dq.back()] > presum[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    return (ans == n + 1) ? -1 : ans;
  }
  // fail: 不能使用滑动窗口
  int shortestSubarray2(vector<int> &nums, int k) {
    int left = 0, right = 0;
    int n = nums.size();
    int ans = n + 1;
    bool great = false;
    for (int sum = 0; right < n; right++) {
      sum += nums[right];
      if (sum >= k)
        great = true;
      while (sum >= k && left < right) {
        sum -= nums[left++];
      }
      // sum < k: real range [left-1, right], len = right - (left - 1) + 1
      // sum >= k:           [left, right]  , len = right - left + 1
      if (great) {
        if (sum < k)
          ans = min(ans, right - left + 2);

        else
          ans = min(ans, right - left + 1);
        great = false;
      }
    }
    if (ans == n + 1)
      return -1;
    return ans;
  }
};

int main() {
  Solution sol;
  // 负值导致不能使用滑动窗口
  vector<int> ex3 = {84, -37, 32, 40, 95};
  printInt("ans: 3 -- ", sol.shortestSubarray(ex3, 167));
  vector<int> ex2 = {2, -1, 2};
  printInt("ans: 3 -- ", sol.shortestSubarray(ex2, 3));
  vector<int> ex1 = {1};
  printInt("ans: 1 -- ", sol.shortestSubarray(ex1, 1));
  return 0;
}