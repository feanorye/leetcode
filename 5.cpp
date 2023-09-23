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
  /*最长回文字符串： 中心扩展法*/
  string longestPalindrome(string s) {
    int n = s.size();
    int loc[2] = {0};
    int ans = 0;
    for (int c = 0; c < 2 * n - 1; c++) {
      int left = c / 2;
      int right = c % 2 + left;
      while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
      }
      int tmp = right - left - 2;
      if (tmp > ans) {
        ans = tmp;
        loc[0] = left + 1;
        loc[1] = right - 1;
      }
    }
    return s.substr(loc[0], ans+1);
  }
};

int main() {
  Solution sol;
  cout << "ans: aba -- " << sol.longestPalindrome("aabac");
  return 0;
}