#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
private:
  int gcd(int a, int b) {
    if (a < b) {
      std::swap(a, b);
    }
    int d = a % b;
    while (d != 0) {
      a = b;
      b = d;
      d = a % b;
    }
    return b;
  }

public:
  int minOperations2(vector<int> &nums) {
    int n = nums.size();
    //首先判断是否存在答案：整个数组的gcd为1
    int g = nums[0];
    for (int i = 1; i < n; i++) {
      g = gcd(g, nums[i]);
    }
    if (g != 1)
      return -1;
    // 其次检查是否已经存在1,存在则为 n - cnt1
    int cnt1 = 0;
    for (int v : nums) {
      if (v == 1)
        cnt1++;
    }
    if (cnt1 > 0)
      return n - cnt1;
    // 最后则为将其中一个子数组转换为1，答案：minSize - 1 + n - 1
    int minSize = INT32_MAX;
    for (int i = 0; i < n; i++) {
      int g = nums[i];
      for (int j = i + 1; j < n; j++) {
        g = gcd(g, nums[j]);
        if (g == 1) {
          minSize = min(minSize, j - i + 1);
          break;
        }
      }
    }
    return minSize - 1 + n - 1;
  }
  int minOperations(vector<int> &nums) {
    // 利用
    // 1. gcd(gcd(x,y),z) = gcd(x,y,z)
    // 2. gcd每增加一个元素，其值要么相同，要么最小除以2
    int n = nums.size();
    //首先判断是否存在答案：整个数组的gcd为1
    int g = nums[0];
    for (int i = 1; i < n; i++) {
      g = gcd(g, nums[i]);
    }
    if (g != 1)
      return -1;
    // 其次检查是否已经存在1,存在则为 n - cnt1
    int cnt1 = 0;
    for (int v : nums) {
      if (v == 1)
        cnt1++;
    }
    if (cnt1 > 0)
      return n - cnt1;
    // 记录以i为右边界的子数组：[gcd1, 相同gcd1的最右的左边界]
    vector<pair<int, int>> ga;
    int minSize = INT32_MAX;
    for (int i = 0; i < n; i++) {
      ga.emplace_back(nums[i], i);
      int j = 0;
      for (auto &p : ga) {
        p.first = gcd(p.first, nums[i]);
        if (ga[j].first == p.first) {
          ga[j].second = p.second;
        } else {
          ga[++j] = std::move(p);
        }
      }
      ga.resize(j + 1);
      if (ga[0].first == 1) {
        minSize = min(minSize, i - ga[0].second + 1);
      }
    }
    return minSize + n - 2;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {2, 6, 3, 4};
  printInt("ans: 4 -- ", sol.minOperations(ex1));
  return 0;
}