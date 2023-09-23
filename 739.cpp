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
  // 返回：ans[i] == 第i天后更高气温离第i天的时间
  vector<int> dailyTemperatures2(vector<int> &temperatures) {
    // 单调栈 [73,74,75,71,69,72,76,73]
    // 反向遍历，存储idx
    // 遇到新的值：t[i] >= top -> pop() until st.empty() -> push(i)
    //                 < top, push(i)
    int n = temperatures.size();
    stack<int> st;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty()) {
        int idx = st.top();
        if (temperatures[i] < temperatures[idx]) {
          ans[i] = idx - i;
          break;
        } else {
          st.pop();
        }
      }
      st.push(i);
    }
    return ans;
  }
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // 无辅助栈做法
    // 反向遍历，当遍历到i时，[i+1:n]已经有了答案，该答案形成了一个递增链表
    int len = temperatures.size();
    vector<int> ans(len, 0);
    for (int i = len - 2; i >= 0; i--) {
      for (int j = i + 1; j < len;) {
        if (temperatures[i] < temperatures[j]) {
          ans[i] = j - i;
          break;
        } else {
          if (ans[j] == 0)
            break;
          j = j + ans[j];
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {73, 74, 75, 71, 69, 72, 76, 73};
  printV(sol.dailyTemperatures(ex1), "ans: ");
  return 0;
}