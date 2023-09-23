#include "listnode.h"
#include <algorithm>
#include <deque>
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
using std::deque;
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
  map<long long, int> prefix;
  int target;
  int preOrder(TreeNode *root, long long cur_sum) {
    int res = 0;
    cur_sum += root->val;
    if (prefix.count(cur_sum - target) > 0) {
      res += prefix[cur_sum - target];
    }
    // 查找之后再+1，否则([1], 0)会失败 
    prefix[cur_sum]++;
    if (root->left) {
      res += preOrder(root->left, cur_sum);
    }
    if (root->right) {
      res += preOrder(root->right, cur_sum);
    }
    prefix[cur_sum]--;
    return res;
  }

public:
  /* 二叉树路径之和满足target的条数
  ** 要求：只能从父节点向子节点出发
  ** 注意：负值目标
  ** 前序遍历 + 前缀和 ==》参考560
  */
  int pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return 0;
    }
    prefix.clear();
    prefix[0] = 1;
    target = targetSum;
    return preOrder(root, 0);
  }
};

int main() {
  Solution sol;
  vector<int> ex2{-2, INT32_MIN, -3};
  auto root2 = Create_tree(ex2);
  printInt("ans: 1 -- ", sol.pathSum(root2, -5));
  vector<int> ex1 = {10, 5, -3, 3, 2, INT32_MIN, 11, 3, -2, INT32_MIN, 1};
  auto root1 = Create_tree(ex1);
  printInt("ans: 3 -- ", sol.pathSum(root1, 8));
  return 0;
}