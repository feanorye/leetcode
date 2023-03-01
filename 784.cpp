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
private:
  bool check(char c) {
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
      return true;
    return false;
  }
  void helper(vector<string> &ans, string &str, string cur_str, int ind,
              int n) {
    while (ind < n && !check(str[ind]))
      cur_str += str[ind++];
    if (ind == n) {
      ans.push_back(cur_str);
    } else {
      helper(ans, str, cur_str + str[ind], ind + 1, n);
      if (str[ind] <= 'Z')
        cur_str.push_back(str[ind] + 'a' - 'A');
      else
        cur_str.push_back(str[ind] - 'a' + 'A');
      helper(ans, str, cur_str, ind+1, n);
    }
  }

public:
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    string st = "";
    helper(ans, s, st, 0, s.size());
    return ans;
  }
};

int main() {
  Solution sol;
  printStrA(sol.letterCasePermutation("a1bb2S"));
  return 0;
}