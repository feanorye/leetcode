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
// 并查集：同一变量的多个引用、朋友圈
class UnionF {
private:
  map<int, int> parent;
  map<int, int> count;

public:
  UnionF(vector<int> &nums) {
    for (int i : nums) {
      parent[i] = i;
      count[i] = 1;
    }
  }
  /*
  ** 返回x的parent
  */
  int find(int x) {
    if (parent.count(x) < 1)
      return INT32_MIN;
  // 路径压缩
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  /*
   * Return: new merged tree's size
   */
  int merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    // todo:为什么？
    if (rootx == rooty)
      return count[rooty];
    parent[rootx] = rooty;
    count[rooty] += count[rootx];
    return count[rooty];
  }
  bool connected(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    return rootx == rooty;
  }
};

class Solution {
public:
  // 找到最长连续子数组
  int longestConsecutive(vector<int> &nums) {
    // 写的并查集不能处理单个元素
    if (nums.size() == 0)
      return 0;
    UnionF uf(nums);
    // 最小长度为1
    int ans = 1;
    for (int e : nums) {
      if (uf.find(e + 1) != INT32_MIN) {
        ans = max(ans, uf.merge(e, e + 1));
      }
    }
    return ans;
  }
  int longestConsecutive2(vector<int> &nums) {
    // map做法
    std::unordered_map<int, int> hash;
    for (int e : nums) {
      hash[e] = e;
    }
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      // 找到左边界
      if (!hash.count(nums[i] - 1)) {
        int right = hash[nums[i]];
        while (hash.count(right + 1))
          right++;
        ans = max(ans, right - nums[i] + 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {4,  0,  -4, -2, 2, 5, 2,  0, -8, -8, -8,
                     -8, -1, 7,  4,  5, 5, -4, 6, 6,  -3};
  std::sort(ex3.begin(), ex3.end());
  printInt("ans: 5 -- ", sol.longestConsecutive(ex3));
  vector<int> ex2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  printInt("ans: 9 -- ", sol.longestConsecutive(ex2));
  vector<int> ex1 = {100, 4, 200, 1, 3, 2};
  printInt("ans: 4 -- ", sol.longestConsecutive(ex1));
  return 0;
}