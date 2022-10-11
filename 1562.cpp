#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
class Solution {
public:
  //单调栈： 不懂
  int findLatestStep(vector<int> &arr, int m) {
    int n = arr.size();
    vector<int> t(n + 2, n + 2);
    for (int i = 0; i < n; i++)
      t[arr[i]] = i;
    stack<int> st;
    int ans = -1;
    for (int i = 0; i < n+2; i++) {
      if (!st.empty()) {
        while (t[st.top()] < t[i]) {
          st.pop();
          if (i - st.top() - 1 == m) {
            //左边界和右边界之间，即arr全部元素
            if (st.top() == 0 && i == (int)(arr.size() + 1))
              return arr.size();
            int tmp = min(t[st.top()], t[i]);
            if (tmp < n && tmp > ans)
              ans = tmp;
          }
        }
      }
      st.push(i);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {6, 7, 8, 1, 2, 3, 4, 5};
  printInt("ans: 7 -- ", sol.findLatestStep(ex3, 3));
  vector<int> ex1 = {3, 1, 5, 4, 2};
  printInt("ans: -1 -- ", sol.findLatestStep(ex1, 2));
  printInt("ans: 4 -- ", sol.findLatestStep(ex1, 1));
  vector<int> ex2 = {3, 5, 1, 2, 4};
  printInt("ans: 4 -- ", sol.findLatestStep(ex2, 1));
  printInt("ans: 5 -- ", sol.findLatestStep(ex2, 5));
  return 0;
}