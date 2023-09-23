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
  bool isValid(string s) {
    vector<char> st;
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[') {
        st.push_back(c);
      } else {
        if ((st.size() > 0) &&
            ((c == ')' && st.back() == '(') || (c == '}' && st.back() == '{') ||
             (c == ']' && st.back() == '['))) {
          st.pop_back();
        } else {
          return false;
        }
      }
    }
    return st.size() == 0;
  }
};

int main() {
  Solution sol;
  cout << sol.isValid("]") << endl;
  return 0;
}