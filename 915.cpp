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
  /* @brief: split vector to [left, right], all left <= right
   * @result:
   *  time: o(n); space: o(1)
   */
  int partitionDisjoint(vector<int> &nums) {
    int n = nums.size();
    int cur_max = nums[0], left_pos = 0, left_max = cur_max;
    // cur_max <= all_right_ele
    for (int i = 1; i < n; i++) {
      cur_max = max(cur_max, nums[i]);
      if (left_max > nums[i]) {
        left_pos = i;
        left_max = cur_max;
      }
    }
    return left_pos + 1;
  }
  int partitionDisjoint2(vector<int> &nums) {
    int n = nums.size();
    vector<int> small(n + 1, 0);
    int m = 1e6 + 7;
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] < m)
        m = nums[i];
      small[i] = m;
    }
    m = -1;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] > m)
        m = nums[i];
      if (m <= small[i + 1])
        return i + 1;
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {5, 0, 3, 8, 6};
  printInt("ans: 3 -- ", sol.partitionDisjoint(ex2));

  vector<int> ex1 = {4, 3, 5, 1, 0, 9};
  printInt("ans: 5 -- ", sol.partitionDisjoint(ex1));
  return 0;
}