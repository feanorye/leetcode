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
  int minLength(string &&s) {
    int left = 1, ans = 0, n = s.size();

    while (left > 0) {
      int prev = 0;
      left = 0;
      ans = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          continue;
        }
        if ((s[i] == 'D' && s[prev] == 'C') || (s[i] == 'B' && s[prev] == 'A')) {
          s[prev] = '0';
          s[i] = '0';
          left++;
        } else {
          prev = i;
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  // 总是debug出错？被认为病毒
  printInt("ans: 2 -- ", sol.minLength(string{"ABFCACDB"}));
  printInt("ans: 5 -- ", sol.minLength(string{"ACBBD"}));
  return 0;
}