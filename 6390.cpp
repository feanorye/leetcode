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
  // 长度为k的子数组，美丽值：第x小的数为负，则为该值，否则为0
  // 返回所有子数组的美丽值
  // todo: 时间10%
  vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
    // 需要维护子数组中第x小的数：1. 二叉搜索树中序遍历
    // 2. multiset: 两个有序区间，维护两个空间的数量，使其 m1 < m2, m1.size = x
    vector<int> subarr{nums.begin(), nums.begin() + k};
    std::sort(subarr.begin(), subarr.end());
    std::multiset<int> mset1{subarr.begin(), subarr.begin() + x};
    std::multiset<int> mset2{subarr.begin() + x, subarr.end()};
    vector<int> ans{min(*prev(mset1.end()), 0)};
    int len = nums.size();

    for (int i = k; i < len; i++) {
      int rm_val = nums[i - k];
      int ins_val;
      if (mset1.find(rm_val) != mset1.end()) {
        // erase(x) 会把重复值全部删掉，故使用erase(position)
        mset1.erase(mset1.find(rm_val));
        // mset2可能为空
        if (!mset2.empty() && *mset2.begin() < nums[i]) {
          ins_val = *mset2.begin();
          mset2.erase(mset2.begin());
          mset2.insert(nums[i]);
        } else {
          ins_val = nums[i];
        }
        mset1.insert(ins_val);
      } else {
        mset2.erase(mset2.find(rm_val));
        // mset1必不为空
        auto it_min1 = prev(mset1.end());
        if (*it_min1 > nums[i]) {
          ins_val = *it_min1;
          mset1.erase(it_min1);
          mset1.insert(nums[i]);
        } else {
          ins_val = nums[i];
        }
        mset2.insert(ins_val);
      }
      ans.push_back(min(*prev(mset1.end()), 0));
    }
    return ans;
  }
  // 评论区代码：比我快
  vector<int> getSubarrayBeauty2(vector<int> &nums, int k, int x) {
    // multiset<int> a, b;//a放前x小的数
    vector<int> hamu(nums.begin(), nums.begin() + k);
    sort(hamu.begin(), hamu.end());
    int n = nums.size();
    // 初始化a, b。 并且维护 a中的最大值 <= b中的最小值

    std::multiset<int> a{hamu.begin(), hamu.begin() + x};
    std::multiset<int> b{hamu.begin() + x, hamu.end()};

    vector<int> ans;
    ans.emplace_back(min(*prev(a.end()), 0));

    for (int i = 0; i + k < n; ++i) {
      if (nums[i + k] <= *prev(a.end())) {
        a.emplace(nums[i + k]);
        auto it_a = a.find(nums[i]);
        if (it_a != a.end()) {
          a.erase(it_a);
        } else {
          auto it_b = b.find(nums[i]);
          b.erase(it_b);
          int max_a = *prev(a.end());
          a.erase(prev(a.end()));
          b.emplace(max_a);
        }
      } else {
        b.emplace(nums[i + k]);
        auto it_b = b.find(nums[i]);
        if (it_b != b.end()) {
          b.erase(it_b);
        } else {
          auto it_a = a.find(nums[i]);
          a.erase(it_a);
          int min_b = *b.begin();
          b.erase(b.begin());
          a.emplace(min_b);
        }
      }
      ans.push_back(min(*prev(a.end()), 0));
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex3{-6, 40, -38, -36, -36, -4, -38, -43, 8};
  printV(sol.getSubarrayBeauty(ex3, 2, 2), "ans:[0,0,-36,-36,-4,-4,-38,0]");
  vector<int> ex2{5};
  printV(sol.getSubarrayBeauty(ex2, 1, 1), "ans: 0 -- ");
  vector<int> ex1{1, -1, -3, -2, 3};
  printV(sol.getSubarrayBeauty(ex1, 3, 2), "ans:[-1,-2,-2] -- ");
  return 0;
}