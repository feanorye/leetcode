#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
  // s中包含t所有元素的最小子串
  string minWindow(string s, string t) {
    // 子串->连续区间->最小->滑动窗口：维护一个可行解区间
    vector<int> cnt(128, 0);
    int needCnt = t.size();
    for (char c : t) {
      cnt[c]++;
    }
    int res[2] = {0, INT32_MAX};
    for (int l = 0, r = 0; r < s.size();r++) {
      if (cnt[s[r]] > 0) {
        needCnt--;
      }
      cnt[s[r]]--;
      if (needCnt == 0) {
        while (true) {
          // 如果为负值，则需要丢弃，移动左边界
          if (cnt[s[l]] < 0) {
            // 顺序不能颠倒
            cnt[s[l]]++;
            l++;
          } else if (cnt[s[l]] == 0) {
            break;
          }
        }
        if (r - l < res[1] - res[0]) {
          res[0] = l;
          res[1] = r;
        }
        // 这里需要移动左边界，继续寻找可行解
        cnt[s[l]]++;
        l++;
        needCnt++;
      }
    }
    if (res[1] > s.size())
      return {""};
    return s.substr(res[0], res[1] - res[0] + 1);
  }
};

int main() {
  Solution sol;
  cout << sol.minWindow("ADOBECODEBANC", "ABC");
  return 0;
}