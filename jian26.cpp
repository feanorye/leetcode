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
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (A == nullptr || B == nullptr)
      return false;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty()) {
      TreeNode *anode = q.front();
      q.pop();
      if (anode->val == B->val && validate(anode, B))
        return true;
      if (anode->left)
        q.push(anode->left);
      if (anode->right) {
        q.push(anode->right);
      }
    }
    return false;
  }
  bool validate(TreeNode *a, TreeNode *b) {
    if (a == nullptr || a->val != b->val)
      return false;
    if (b->left) {
      if (!(validate(a->left, b->left)))
        return false;
    }
    if (b->right) {
      if (!(validate(a->right, b->right)))
        return false;
    }
    return true;
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