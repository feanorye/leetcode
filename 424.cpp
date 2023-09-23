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
  int characterReplacement2(string s, int k) {
    /**
     * 相较滑动窗口，太过麻烦
     * 1. No connection: max(len) + k
     * 2. connect one side: max(len) + max(left, right) + (k - kc)
     * 3. Connect both side: len + left + right + (k - kc)
     * prev, cur, next: {length, idx0}
     * 假设>= 3个连接呢？
     */
    using PII = pair<int, int>; // {idx, len}
    int len = s.size();
    vector<vector<PII>> mem(26);
    int l = 0, r = 0;
    for (; r < len; r++) {
      if (s[r] != s[l]) {
        mem[s[l] - 'A'].emplace_back(l, r - l);
        l = r;
      }
    }
    mem[s[l] - 'A'].emplace_back(l, r - l);

    int ans = 0;
    for (auto &arr : mem) {
      int asize = arr.size();
      if (asize == 0) {
        continue;
        ;
      }
      int lspace = 1024, rspace = 1024;
      int left = 0, right = 0, cur = 0;
      int cur_idx = 0;
      // [left]--[cur]--[right]
      cur_idx = arr[0].first;
      cur = arr[0].second;

      for (int i = 0; i < asize; i++) {
        if (i + 1 < asize) {
          right = arr[i + 1].second;
          rspace = arr[i + 1].first - (cur_idx + cur);
        } else {
          rspace = 1024;
        }
        int pk = min(cur_idx + len - cur_idx - cur, k);
        ans = max(ans, cur + pk);
        if (k >= lspace + rspace) {
          ans = max(ans, cur + left + right);
        } else if (k >= lspace) {
          ans = max(ans, cur + left + k);
        } else if (k >= rspace) {
          ans = max(ans, cur + right + k);
        }
        // next loop
        left = cur;
        lspace = rspace;
        cur_idx = rspace + (cur_idx + cur);
        cur = right;
      }
    }
    return ans;
  }
  int characterReplacement(string s, int k) {
    // 滑动窗口
    // todo: 理解，和424有何不同？
    vector<int> freq(26, 0);
    int left = 0, right = 0;
    int len = s.size();
    int maxcnt = 0;
    int ans = 0;
    for (; right < len;) {
      freq[s[right] - 'A']++;
      // 如果一个子字符串 + k > 原本maxcnt + k， 必会更新maxcnt
      // maxcnt记录的的确是整个字符串的最大频率
      maxcnt = max(maxcnt, freq[s[right++] - 'A']);
      // 若不移动，说明k可以把 [left:right] 内的所有字符改为一致
      while (right - left > maxcnt + k) {
        // 此时说明无效区域 > k
        freq[s[left++] - 'A']--; // freq数组记录实时数量
      }
      // 字符串可换空间可能 < k
      ans = right - left;
      // 似乎不需要max(ans, right - left)，因为right - left会保持在maxcnt + k
    }
    return ans;
  }
};

int main() {
  Solution sol;
  printInt("ans: 5 -- ", sol.characterReplacement("AAACDBBCEDBB", 2));
  printInt("ans: 6 -- ", sol.characterReplacement("AAACDBBCDBB", 2));
  printInt("ans: 4 -- ", sol.characterReplacement("AAAA", 2));
  printInt("ans: 6 -- ", sol.characterReplacement("AASBAA", 2));
  return 0;
}