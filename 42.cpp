#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;
//单调栈-雨水问题
class Solution {
public:
  int trap(vector<int> &height) {
    stack<int> st;
    int n = height.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      //希望找到严格大于height[i]的值
      while (!st.empty() && height[i] > height[st.top()]) {
        int h = height[st.top()];
        st.pop();
        if (st.empty())
          break;
        int distance = i - st.top() - 1;
        int wh = min(height[st.top()], height[i]) - h;
        ans += wh * distance;
      }
      st.push(i);
    }
    return ans;
  }
  //想错了
  int trap2(vector<int> &height) {
    stack<int> st;
    int n = height.size();
    vector<int> bigger(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      //希望找到严格大于height[i]的值
      while (!st.empty() && height[i] >= height[st.top()]) {
        st.pop();
      }
      if (!st.empty())
        bigger[i] = st.top();
      st.push(i);
    }
    // printV(bigger, "Bigger mat: ");
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (height[i] > height[i + 1] && bigger[i + 1] != -1) {
        int sub = min(height[i], height[bigger[i + 1]]) - height[i + 1];
        int length = bigger[i + 1] - i - 1;
        /*         cout << "sub " << i << ": " << height[i + 1] << " " << sub
                     << " area:" << (sub * length) << endl;
                ans += sub * length; */
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {4, 2, 0, 3, 2, 5};
  printInt("ans: 9 -- ", sol.trap(ex2));
  vector<int> ex1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  printInt("ans: 6 -- ", sol.trap(ex1));
  return 0;
}