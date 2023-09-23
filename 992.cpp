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
  /* 找出不同元素恰好为k的子数组数目，类似6900， 907：贡献法 + 单调栈 */
  int subarraysWithKDistinct2(vector<int> &nums, int k) {
    // todo: 双指针
    // {2,1,1,1,2}
    //
    map<int, int> cnt;
    map<int, int> cnt_arr; // [prev_left, left]之间的统计
    int prev_cnt = 0;
    int left = 0; // left实际指代的是可重复的左数组个数
    int prev_left = 0;
    int ans = 0;

    for (int e : nums) {
      cnt[e]++;
      cnt_arr[e]++;

      if (cnt.size() == k && cnt_arr.size() != prev_cnt) {
        for (int i = prev_left; i < left; i++) {
          if (cnt_arr.count(nums[i]) > 0) {
            cnt_arr.erase(nums[i]);
          }
        }
        prev_cnt = cnt_arr.size();
        prev_left = left;
      }
      while (cnt.size() == k) {
        int x = nums[left++];
        if (--cnt[x] == 0) {
          cnt.erase(x);
        }
      }
      ans += left - prev_left;
    }
    return ans;
  }
  // 子数组的数量：{3,4,[4,3,5],5,4,5} k = 3
  // left * (len - right) = 3 * (8 - 4) = 12
  // 另一种角度则为
  // ans += left for i in range(left, len) if cnt[left:right] == k
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    // 连续子数组 -> 恰好为k -> 双指针
    // 个数 >= k
    // {1,3,1,2,3}, k = 2
    // {0,0,0,2,3} lower
    // {0,1,2,3,4} upper
    // {1,2,3,3,4,3,2,5,3} k = 3
    //    ^       ^
    // {0,0,0,0,1,1,1,5,5} lower k = 3
    // {0,0,1,1,2,2,5,6,7} upper k = 2
    // 实质为每加入一个nums[i]，更新其左侧可分的子数组数量

    int ans = 0;
    int n = nums.size();
    vector<int> upper(n);
    vector<int> lower(n);
    find(lower, nums, k);
    find(upper, nums, k - 1);
    for (int i = 0; i < n; i++) {
      ans += (upper[i] - lower[i]);
    }
    return ans;
  }
  /* 为nums[0:i+1]找到恰好具有k个不同元素的位置 */
  void find(vector<int> &mem, vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> cnt(n + 1, 0);
    int sum = 0;
    for (int l = 0, r = 0; r < n; r++) {
      int x = nums[r];
      if (cnt[x]++ == 0) {
        sum++;
      }
      // 为什么 > k? 满足恰好 = k的位置
      while (sum > k) {
        int y = nums[l++];
        if (--cnt[y] == 0) {
          sum--;
        }
      }
      // sum < k：l = 0
      // sum = k之后，sum最小为k
      mem[r] = l;
    }
  }
};

int main() {
  Solution sol;
  vector<int> ex3{4, 4, 3, 4, 5, 4, 5, 3, 4};
  printInt("ans: 22 -- ", sol.subarraysWithKDistinct(ex3, 3));
  vector<int> ex2{2, 1, 1, 1, 2};
  printInt("ans: 8 -- ", sol.subarraysWithKDistinct(ex2, 1));
  vector<int> ex1{1, 2, 1, 2, 3};
  printInt("ans: 7 -- ", sol.subarraysWithKDistinct(ex1, 2));
  return 0;
}