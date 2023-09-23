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
  /*
  ** 后序遍历，当前节点和子树氛围内包含两个目标的话，则返回
  ** bug1: 需要检查找到的为同一棵子树，还是分割的两颗子树
  **              root          root
  **             /    \        /    \
  **            a      b      a
  **                            \
  **                             b
  */
  TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q, int &cnt_found) {
    int old_cnt = cnt_found;
    if (root->left != nullptr) {
      TreeNode *lans = dfs(root->left, p, q, cnt_found);
      if (lans != nullptr) {
        return lans;
      }
    }
    if (root->right != nullptr) {
      TreeNode *rans = dfs(root->right, p, q, cnt_found);
      if (rans != nullptr) {
        return rans;
      }
    }
    if (root == p || root == q) {
      cnt_found++;
    }
    if (cnt_found - old_cnt == 2) {
      return root;
    }
    return nullptr;
  }
  // 最近的公共祖先
  TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    int cnt_found = 0;
    return dfs(root, p, q, cnt_found);
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    TreeNode *lans = lowestCommonAncestor(root->left, p, q);
    TreeNode *rans = lowestCommonAncestor(root->right, p, q);
    if (lans == nullptr) {
      return rans;
    }
    if (rans == nullptr) {
      return lans;
    }
    return root; //left && right
  }
};

int main() {
  Solution sol;
  vector<int> ex1{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
  auto root = Create_tree(ex1);
  auto p = find(root, 5);
  auto q = find(root, 1);
  printInt("ans: 3 -- ", sol.lowestCommonAncestor(root, p, q)->val);
  return 0;
}