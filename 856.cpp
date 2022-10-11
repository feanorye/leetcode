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
  int scoreOfParentheses(string s) {
    stack<int> st;
    //final result would be st[0]
    st.push(0);
    for (auto c : s) {
      if (c == '(') {
        st.push(0);
      } else {
        int v = st.top();
        st.pop();
        st.top() += max(2*v,1);
      }
    }
    return st.top();
  }
};

int main() {
  Solution sol;
  printInt("ans: 5 -- ", sol.scoreOfParentheses("(()())()"));
  return 0;
}