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
  string _s;
  std::set<string> _store;
  int _max_cnt;
  int _size_str;
  int _ans_len;

private:
  void dfs(string cur, int pos, int score, int l_rm, int r_rm) {
    // 失效
    if (score < 0 || score > _max_cnt || l_rm < 0 || r_rm < 0) {
      return;
    }
    if (pos == _size_str) {
      if (score == 0) {
        _store.insert(cur);
      }
      return;
    }
    char c = _s[pos];
    if (c == '(') {
      dfs(cur + '(', pos + 1, score + 1, l_rm, r_rm);
      dfs(cur, pos + 1, score, l_rm - 1, r_rm);
    } else if (c == ')') {
      dfs(cur + ')', pos + 1, score - 1, l_rm, r_rm);
      dfs(cur, pos + 1, score, l_rm, r_rm - 1);
    } else {
      dfs(cur + c, pos + 1, score, l_rm, r_rm);
    }
  }

public:
  /*减少字符，使错误括号字符串有效*/
  vector<string> removeInvalidParentheses(string s) {
    /*  回溯：让max_cnt作为左右括号最小值，表示有效括号的最大可能数量
    **    1. '(': score + 1, ')': score - 1 => 0 <= score <= max_cnt生效
    **    2. lrm和rrm：表示左右括号分别应该删除的数量
    */
    int l = 0, r = 0;
    int lrm = 0, rrm = 0;
    for (char c : s) {
      if (c == '(') {
        l++;
        lrm++;
      } else if (c == ')') {
        r++;
        if (lrm > 0) {
          lrm--;
        } else {
          rrm++;
        }
      }
    }
    _s = s;
    _store.clear();
    _max_cnt = min(l, r);
    _size_str = s.size();
    _ans_len = _size_str - lrm - rrm;
    dfs("", 0, 0, lrm, rrm);
    vector<string> ans(_store.begin(), _store.end());
    return ans;
  }
};

int main() {
  Solution sol;
  printV(sol.removeInvalidParentheses("())"), "ans:() -- ");
  return 0;
}