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
    TreeNode* mirrorTree(TreeNode* root) {
      queue<TreeNode *> q;
      if (root == nullptr)
        return nullptr;
      q.push(root);
      while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        TreeNode *tmp;
        tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      return root;
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