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
    0: 00,    1: 01,
    2: 10     3: 11,
    4: 100,   5: 101
    动态规划：
      1. 奇数： dp[x] = dp[x-1] + 1
      2. 偶数： dp[x] = dp[x/2]
  */
  vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    for (int i = 1; i <= num; i++) {
      if (i % 2 == 0) {
        ans[i] = ans[i / 2];
      } else {
        ans[i] = ans[i - 1] + 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}