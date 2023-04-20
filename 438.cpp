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
  // 找到相同字母但是乱序的同样子字符串
  vector<int> findAnagrams(string s, string p) {
    vector<int> symbol(26, 0);
    for (char c : p) {
      symbol[c - 'a']++;
    }
    int a = 0; //不同字符
    for (int cnt : symbol) {
      if (cnt > 0) {
        a++;
      }
    }
    vector<int> ans;
    for (int l = 0, r = 0, b = 0; r < s.size();r++) {
      // 新加入的字符抵消已有字符，当为0时表示该字符和p中相等
      if (--symbol[s[r] - 'a'] == 0)
        b++;
      // 删掉的字符恢复该统计
      if ((r - l + 1) > p.size() && ++symbol[s[l++] - 'a'] == 1)
        b--;
      if (a == b)
        ans.push_back(l);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  printV(sol.findAnagrams("cbaebabacd", "abc"), "ans: [0,6]");
  return 0;
}