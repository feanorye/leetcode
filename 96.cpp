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
#include <tuple>

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
using std::stringstream;
using std::tuple;
using std::greater;

class Solution {
  vector<int> dp;

public:
  Solution() : dp(25, -1) {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
  }
  int numTrees(int n) {
    if (dp[n] > -1)
      return dp[n];
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int left = i - 1, right = n - i;
      if (dp[left] == -1)
        numTrees(left);
      if (dp[right] == -1)
        numTrees(right);
      ans += (dp[left] * dp[right]);
    }
    dp[n] = ans;
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}