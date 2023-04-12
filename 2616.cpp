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
  // 取p对元素，求所有元素对的差的最小值。
  int minimizeMax(vector<int> &nums, int p) {
    std::sort(nums.begin(), nums.end());
    auto check = [&](int mx) {
      int cnt = 0;
      for (int i = 1; i < nums.size();) {
        if (nums[i] - nums[i - 1] <= mx) {
          cnt++;
          i += 2;
        } else {
          i++;
        }
      }
      return cnt >= p;
    };
    int left = 0, right = nums.back() - nums[0];
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() {
  Solution sol;
  return 0;
}