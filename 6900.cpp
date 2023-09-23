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
#include <unordered_set>
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
  // 找到相异元素个数等同于整体相异个数的数组的数量
  int countCompleteSubarrays2(vector<int> &nums) {
    int len = nums.size();
    map<int, int> cnt;
    for (int a : nums) {
      cnt[a]++;
    }
    for (auto &[k, v] : cnt) {
      v = 0;
    }
    int unique_cnt = cnt.size();
    int arr_cnt = 0;
    vector<pair<int, int>> mem;
    for (int l = 0, r = 0; r < len; r++) {
      int a = nums[r];
      if (cnt[a] == 0) {
        arr_cnt++;
      }
      cnt[a]++;

      if (arr_cnt == unique_cnt) {
        for (; l < r; l++) {
          int b = nums[l];
          if (cnt[b] == 1) {
            break;
          }
          cnt[b]--;
        }
        mem.emplace_back(l, r);
        // move l forward
        cnt[nums[l++]]--;
        arr_cnt--;
      }
    }
    int lb = -1, rb = len;
    int ans = 0;
    for (auto [l, r] : mem) {
      ans += (l - lb) * (rb - r);
      lb = l;
    }
    return ans;
  }
  int countCompleteSubarrays(vector<int> &nums) {
    /**
     * {4, 4, 3, 4, 5, 4, 5, 3, 4}
     *  ^ -----> ^
     *  ans = 0, arr = {4, 4, 3, 4, 5}, left = 0
     *  ans = 3, arr = {4, 5}, left = 3
     *  ans = 6, arr = {4, 5, 4}
     *        9,       {4, 5, 4, 5}
     *        9,       {4, 5, 4, 5, 3}
     *        15,      {5, 3}, left = 6
     *        15,      {5, 3, 4}, left = 6
     *        22,      {5, 3, 4}, left = 7
     * 在无完整元素时，left = 0
     * 完整元素后，如 {3,3,4,5,} 4,4 , ans = left * (len - right)
     * 多个完整子数组，则以当前位置的最右子数组为基准. {3, 3, 4, 5, 4, 3, 3}
     * 其实和我的做法一样，只不过我算了两遍
     * 双指针
     */
    int m = std::unordered_set<int>(nums.begin(), nums.end()).size();
    map<int, int> cnt;
    int left = 0;
    int ans = 0;
    for (int v : nums) {
      cnt[v]++;
      // left移动的条件是发现完整子数组
      while (cnt.size() == m) {
        int x = nums[left++];
        if (--cnt[x] == 0)
          cnt.erase(x);
      }
      ans += left;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{2, 1, 1, 1, 2};
  printInt("ans: 8 -- ", sol.countCompleteSubarrays(ex2));
  vector<int> ex1{4, 4, 3, 4, 5, 4, 5, 3, 4};
  printInt("ans: 22 -- ", sol.countCompleteSubarrays(ex1));
  return 0;
}