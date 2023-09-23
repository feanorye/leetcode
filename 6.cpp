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
/*
 * @param s string of to used
 * @param[out] numRows length of row
 * */
  string convert(string s, int numRows) {
    vector<string> ans(numRows);
    int ind = 0, n = s.size();
    while (ind < n) {
      for (int i = 0; i < numRows && ind < n; i++) {
        ans[i].push_back(s[ind++]);
      }
      for (int j = numRows - 2; j > 0 && ind < n; j--) {
        ans[j].push_back(s[ind++]);
      }
    }
    for (int i = 1; i < numRows; i++) {
      ans[0].append(ans[i]);
    }
    return ans[0];
  }
};

int main() {
  Solution sol;
  string ex = {"PAYPALISHIRING"};
  cout << sol.convert(ex, 4) << endl;
  
  return 0;
}