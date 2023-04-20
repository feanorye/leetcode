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
  bool traverse(TreeNode *root, vector<TreeNode *> &fix) {
    if (root->left && traverse(root->left, fix))
      return true;
    TreeNode *pre = fix[0];
    if (pre != nullptr && pre->val > root->val) {
      fix[2] = root;
      if (fix[1] == nullptr)
        fix[1] = pre;
      else
        return true;
    }
    fix[0] = root;
    if (root->right && traverse(root->right, fix))
      return true;
    return false;
  }
  // 二叉搜索树有两个元素顺序颠倒，找到该元素并将其恢复正常
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> fix(3, nullptr);
    traverse(root, fix);
    auto tmp = fix[1]->val;
    fix[1]->val = fix[2]->val;
    fix[2]->val = tmp;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 3, -1, -1, 2};
  TreeNode *root = Create_tree(ex1);
  sol.recoverTree(root);
  return 0;
}