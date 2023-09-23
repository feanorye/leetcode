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
  // "3[a2[c]]" 展开，数字为后面字符重复次数
  string decodeString(string s) {
    stack<pair<int,string>> st;
    string res = "";
    int multi = 0;
    for (char c : s) {
      if (c <= '9' && c >= '0') {
        multi = multi * 10 + (c - '0');
      } else if (c == '[') {
        st.emplace(multi, res);
        multi = 0;
        res = "";
      } else if (c == ']') {
        auto [t, last_s] = st.top();
        st.pop();
        for (int i = 0; i < t; i++) {
          last_s += res;
        }
        res = std::move(last_s);
      } else {
        res.push_back(c);
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  string ex1 = {"3[a2[c]]"};
  string ex2 = {"3[z]2[2[y]pq4[2[jk]e1[f]]]ef"};
  cout << sol.decodeString(ex2) << endl;
  cout << sol.decodeString(ex1) << endl;

  return 0;
}