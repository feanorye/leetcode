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

class Solution {
public:
  int minSwap(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, n + 10));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
      if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1] + 1;
      }
      if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        dp[i][1] = min(dp[i - 1][0] + 1, dp[i][1]);
      }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}