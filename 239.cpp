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
  /*
   * @theory: 单调队列
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();
      dq.emplace_back(i);
    }
    ans.push_back(nums[dq.front()]);
    for (int i = k; i < n; i++) {
      while (!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();
      dq.emplace_back(i);
      while (!dq.empty() && dq.front() <= (i - k))
        dq.pop_front();
      ans.push_back(nums[dq.front()]);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 3, -1, -3, 5, 3, 6, 7};
  printV(sol.maxSlidingWindow(ex1, 3), "ans: [3,3,5,5,6,7] -- ");
  return 0;
}