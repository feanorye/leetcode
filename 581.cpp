#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
  int findUnsortedSubarray1(vector<int> &nums) {
    /**
       {1,4,2,2,3} 注意失序蔓延2,2,3
       {2,3,3,2,4} 注意2对应的左边界，为第一个3
       {1,3,5,4,2} 注意2调整时对应的左边界，并不为第一个失序的5
       单调栈 [1, 2, 3, 7, 6, 6, 9, 2]
       左边界 [n, n, n, n, 3, 3, 3, 1]
       右边界 [n, n ,n, n, 4, 5, 5, 6]
       i = 4, nums[st] = [1,2,3,7], e = 6
       i = 5,            [1,2,3,6], e = 6
       i = 6,            [1,2,3,6], e = 9
       i = 7,            [1,2,3,6,9], e = 2
       i = 8,            [1,2]
     */
    int len = nums.size();
    vector<int> st;//保持递增
    int ans = 0;
    int left = INT32_MAX, left_idx = -1;
    for (int i = 0; i < len; i++) {
      if (!st.empty() && nums[i] < nums[st.back()]) {
        // 当前情况确定i为右边界
        if (left_idx == -1) {//记录stack中的left位置
          left = st.back();
          left_idx = st.size();
        }
        if (nums[left] > nums[i]) {
          int j = left_idx - 1;
          for (; j >= 0; j--) {
            if (nums[st[j]] < nums[i]) {
              left = st[j + 1];
              left_idx = j + 1;
              break;
            }
          }
          if (j <= 0 && nums[st[0]] > nums[i]) {
            left = st[0];
            left_idx = 0;
          }
        }
        ans = i - left + 1;
      }
      if (st.empty() || nums[i] > nums[st.back()]) {
        st.push_back(i);
      }
    }
    return ans;
  }
  /* 三叶题解下墨鳖，研究下，虚拟单调栈 */
  int findUnsortedSubarray2(vector<int> &nums) {
    int maxn = INT_MIN, r = -1;
    int minn = INT_MAX, l = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      // 右边界是否扩展，只和i之前的最大值相关
      (maxn > nums[i]) ? r = i : maxn = nums[i];
      // 左边界是否扩展，只和i以后的最小值相关
      (minn < nums[n - i - 1]) ? l = n - i - 1 : minn = nums[n - i - 1];
    }
    return r == -1 ? 0 : r - l + 1;
  }
  /*  墨鳖 */
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size();
    int l = n - 1, r = 0;
    stack<int> stk;
    for (int i = 0; i < n; i++) { // 最靠开始方向的为左边界
      // 正常为递增顺序，
      // 对于任意0<=i<len, 若存在 j > i 使得 nums[i] > nums[j],
      // i则在修正范围之内
      while (stk.size() && nums[stk.top()] > nums[i])
        l = min(l, stk.top()), stk.pop();
      stk.push(i);
    }
    while (!stk.empty())
      stk.pop();
    for (int i = n - 1; i >= 0; i--) { // 最靠末尾方向的为右边界
      // 从末尾，应为递减
      while (stk.size() && nums[stk.top()] < nums[i])
        r = max(r, stk.top()), stk.pop();
      stk.push(i);
    }
    return r - l > 0 ? r - l + 1 : 0;
  }
};

int main() {
  Solution sol;
  vector<int> ex5{2, 3, 1, 4, 5};
  printInt("ans: 3 -- ", sol.findUnsortedSubarray(ex5));
  // 每个数对应的范围为, ex4仔细看看
  vector<int> ex4{1, 3, 5, 4, 2};
  printInt("ans: 4 -- ", sol.findUnsortedSubarray(ex4));
  // 左边界不是单调栈顶
  vector<int> ex3{9, 2, 6, 3, 10, 11, 14, 11, 12, 20};
  printInt("ans: 9 -- ", sol.findUnsortedSubarray(ex3));
  vector<int> ex2{2, 2, 3, 3, 2, 4};
  printInt("ans: 3 -- ", sol.findUnsortedSubarray(ex2));
  vector<int> ex1{1, 4, 2, 2, 3};
  printInt("ans: 4 -- ", sol.findUnsortedSubarray(ex1));
  vector<int> ex{1, 2, 3};
  printInt("ans: 0 -- ", sol.findUnsortedSubarray(ex));
  return 0;
}