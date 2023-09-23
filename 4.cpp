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
  /* 返回小于等于target的数量
   * {2,2,2} <=2的数量为3，<=3的数量为3，<=1的数量为0
   * size: 0, >0
   * 全部< target, ==, >
   */
  int bisearch(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    // 最后一个<= target的位置
    while (l < r) {
      int m = (l + r + 1) >> 1;
      // <=: [m, r]
      // >:  [l, m-1]
      if (nums[m] <= target) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return (n > 0 && nums[l] <= target) ? l + 1 : l;
  }

public:
  // 两个排序序列的中位数
  // 因为已排序，很容易得知小于一个数的数量
  // todo: 不太对
  double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int l = -1e6;
    int r = 1e6;
    // 2n: n-1, n == (2n-1)/2, 2n/2
    // 2n+1: n,n == 2n/2, (2n+1)/2
    auto check = [&nums1, &nums2, n1, n2, this](int x, int p) {
      // 中位数的特点：<x的数量<=n-1, <x+1的数量>n-1
      int num = bisearch(nums1, x - 1) + bisearch(nums2, x - 1);
      int num2 = bisearch(nums1, x) + bisearch(nums2, x);
      return num <= p && num2 > p;
    };
    auto search = [&check, n1, n2](int l, int r, int p) {
      while (l < r) {
        int m = (l + r) >> 1;
        if (check(m, p)) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      return l;
    };
    int ans = search(l, r, (n1 + n2 - 1) / 2);
    ans += search(ans, 1e6, (n1 + n2) / 2);
    return static_cast<double>(ans) / 2;
  }
  // todo: 不太对
  double findMedianSortedArrays3(vector<int> &nums1, vector<int> &nums2) {
    // 假设ex1 {1,2,3,4,5}, ex2{1}
    // 从两个数组中枚举k个数

    int n1 = nums1.size();
    int n2 = nums2.size();

    // 2n: (2n-1)/2 = n-1, 2n/2 = n
    // 2n+1: 2n/2 = n, (2n+1)/2 = n
    int k1 = (n1 + n2 - 1) / 2;
    int k2 = (n1 + n2) / 2;
    if (n1 == 0) {
      return static_cast<double>((nums2[k1] + nums2[k2])) / 2;
    }
    if (n2 == 0) {
      return static_cast<double>((nums1[k1] + nums1[k2])) / 2;
    }
    auto getIdxK = [&](int k) -> double {
      int l1 = 0, r1 = min(k, n1 - 1);
      // arr1: 取m+1
      // arr2: 取k-m
      while (l1 < r1) {
        int m = (l1 + r1) >> 1;
        // >  :[l,m]
        // == :[m]
        // <  :[m,r]
        if (nums1[m] == nums2[k - m - 2]) {
          l1 = m;
          break;
        } else if (nums1[m] > nums2[k - m - 2]) {
          r1 = m - 1;
        } else {
          l1 = m + 1;
        }
      }
      return (k - l1 - 2 < 0 || nums1[l1] > nums2[k - l1 - 2])
                 ? nums1[l1]
                 : nums2[k - l1 - 2];
    };
    return (getIdxK(k1) + getIdxK(k2)) / 2;
  }
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // nums1{}, nums2{}, 分别取k/2个数
    // a[k/2-1] < b[k/2-1], 因为a[a<=a[k/2-1]].size = k/2-1,
    // b[b<=a[k/2-1]]最大为k/2-1 则a[0:k/2+1]的数不可能为第k小的数
    int n1 = nums1.size();
    int n2 = nums2.size();

    // 2n: (2n-1)/2 = n-1, 2n/2 = n
    // 2n+1: 2n/2 = n, (2n+1)/2 = n
    int k1 = (n1 + n2 - 1) / 2;
    int k2 = (n1 + n2) / 2;

    auto getIdxK = [&nums1, &nums2](int s1, int e1, int s2, int e2,
                                    int k) -> double {
      while (k > 0) {
        if (e1 < s1) {
          return nums2[s2 + k];
        }
        if (e2 < s2) {
          return nums1[s1 + k];
        }
        int c1 = min(s1 + k / 2 - 1, e1);
        int c2 = min(s2 + k / 2 - 1, e2);
        // k == 1时，k/2-1 == -1，出错
        if (k == 1) {
          c1 = s1;
          c2 = s2;
        }
        // <: k/2 - 1 + k/2 - 1 = k - 2, 丢掉小于的数组，新起点s1 = s1 + k/2
        // =
        // >: s2 = s2 + k /2 = c2 + 1
        if (nums1[c1] < nums2[c2]) {
          k -= c1 - s1 + 1;
          s1 = c1 + 1;
        } else {
          k -= c2 - s2 + 1;
          s2 = c2 + 1;
        }
      }
      if (s1 > e1) {
        return nums2[s2];
      }
      if (s2 > e2) {
        return nums1[s1];
      }
      return min(nums1[s1], nums2[s2]);
    };
    return (getIdxK(0, n1 - 1, 0, n2 - 1, k1) +
            getIdxK(0, n1 - 1, 0, n2 - 1, k2)) /
           2;
  }
};

int main() {
  Solution sol;
  vector<int> ex5{1, 3};
  vector<int> ex6{2};
  cout << "ans: 2 -- " << sol.findMedianSortedArrays(ex5, ex6) << endl;

  vector<int> ex3{1, 2};
  vector<int> ex4{3, 4};
  cout << "ans: 2.5 -- " << sol.findMedianSortedArrays(ex3, ex4) << endl;

  vector<int> empty_ex;
  vector<int> ex1{2, 2, 2};
  cout << "ans: 2 -- " << sol.findMedianSortedArrays(ex1, empty_ex) << endl;
  return 0;
}