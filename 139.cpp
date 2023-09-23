#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
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
using std::set;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
public:
  // find a str start from idx, then try next str.
  bool helper(string &s, std::set<string> &strset, string tmp, int idx, int len,
              int maxlen) {
    if (idx == len) {
      return true;
    }
    for (int i = idx; i - idx < maxlen && i < len; i++) {
      tmp.push_back(s[i]);
      if (strset.count(tmp) > 0) {
        if (helper(s, strset, string{}, i + 1, len, maxlen)) {
          return true;
        }
      }
    }
    return false;
  }
  // 超时
  bool wordBreak1(string s, vector<string> &wordDict) {
    std::set<string> strset;
    size_t maxlen = 0, len = s.size();
    for (string &item : wordDict) {
      strset.insert(item);
      maxlen = std::max(item.size(), maxlen);
    }
    std::string tmp;
    return helper(s, strset, string{}, 0, len, maxlen);
  }
  // 序列DP
  bool wordBreak(string s, vector<string> &wordDict) {
    set<string> strset{wordDict.begin(), wordDict.end()};
    // dp[i]: s[0:i] can represent in wordDict, index i not include
    // dp[i]: dp[j] && s[j:i] in wordDict
    int len = s.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for (int i = 1; i <= len; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j] && strset.count(s.substr(j, i - j)) > 0) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[len];
  }
};

int main() {
  Solution sol;
  vector<string> ex1{"leet", "code"};
  printInt("ans: true -- ", sol.wordBreak(string{"leetcode"}, ex1));
  return 0;
}