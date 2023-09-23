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
  int maxNonDecreasingLength2(vector<int> &nums1, vector<int> &nums2) {
    int ans = 1;
    int pre_cnt[2] = {1, 1};
    int len = nums1.size();

    auto connect = [&nums1, &nums2, &pre_cnt](int cmp_idx, int val) -> int {
      int length = 1;
      if (val >= nums1[cmp_idx]) {
        length = max(length, pre_cnt[0] + 1);
      }
      if (val >= nums2[cmp_idx]) {
        length = max(length, pre_cnt[1] + 1);
      }
      return length;
    };
    for (int i = 1; i < len; i++) {
      int p1 = connect(i - 1, nums1[i]);
      int p2 = connect(i - 1, nums2[i]);
      ans = max(ans, max(p1, p2));
      pre_cnt[0] = p1;
      pre_cnt[1] = p2;
    }
    return max(ans, max(pre_cnt[0], pre_cnt[1]));
  }
  int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2) {
    int f0 = 1, g0 = 1, ans = 1;
    int len = nums1.size();
    for (int i = 1; i < len; i++) {
      int f = 1, g = 1;
      if (nums1[i - 1] <= nums1[i]) {
        f = max(f, f0 + 1);
      }
      if (nums2[i - 1] <= nums1[i]) {
        f = max(f, g0 + 1);
      }
      if (nums1[i - 1] <= nums2[i]) {
        g = max(g, f0 + 1);
      }
      if (nums2[i - 1] <= nums2[i]) {
        g = max(g, g0 + 1);
      }
      ans = max(ans, max(f, g));
      f0 = f;
      g0 = g;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2{{4, 16, 10, 8}, {8, 4, 1, 9}};
  printInt("ans: 3 -- ", sol.maxNonDecreasingLength(ex2[0], ex2[1]));
  vector<vector<int>> ex1 = {{1, 3, 2, 1}, {2, 2, 3, 4}};
  printInt("ans: 4 -- ", sol.maxNonDecreasingLength(ex1[0], ex1[1]));
  return 0;
}