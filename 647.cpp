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
  /*
    回文字符串统计
    1. aaaaa
    2. abcba
    3. abccba: 3 + 6
    4. abcbdbc: 3 + 7
  */
  int countSubstrings2(string s) {
    /*
      动态规划： dp[i,j] str[i:j+1]是否为回文字符串
      状态转移：aba, aa
        if str[i] = str[j] && (j - i < 2 || dp[i+1,j-1]):
          dp[i,j] = true
    */
    int ans = 0;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
      for (int i = 0; i <= j; i++) {
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          ans++;
        }
      }
    }
    return ans;
  }
  int countSubstrings(string s) {
    /*中心扩展法:
          单位为1的中心点：len, 单位为2的中心点len-1
          0. left: 0 right: 0
          1.       0        1
          2.       1        1
          3.       1        2
          2*len.   len      len
    */
    int len = s.size();
    int ans = 0;
    for (int center = 0; center < 2 * len - 1; center++) {
      int left = center / 2;
      int right = left + center % 2;
      while (left >= 0 && right < len && s[left] == s[right]){
        ans++;
        left--;
        right++;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  printInt("ans: 10 -- ", sol.countSubstrings("abcbdbc"));
  return 0;
}