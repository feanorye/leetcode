#include "tree.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::queue;
using std::stack;
using std::vector;

// Definition for a binary tree node.

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    return check(root, root);
  }
  bool check(TreeNode *left, TreeNode *right) {
    if (!left && !right)
      return true;
    if (!left || !right)
      return false;
    return (left->val == right->val) && check(left->left, right->right) &&
           check(left->right, right->left);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ans;

  vector<int> ex1 = {1, 2, 3, 0, 0, 4, 5};
  TreeNode *head = createTree(ex1);
  // ans = sol.levelOrder(head);
  display(ans);
  deleteTree(head);
  return 0;
}