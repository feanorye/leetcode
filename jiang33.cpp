#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include "tree.h"

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
  // 33
  vector<vector<int>> levelOrder2(TreeNode *root) {
    vector<vector<int>> ans;
    std::queue<TreeNode *> q;
    // must handle nullptr condition
    if (root == nullptr)
      return ans;
    TreeNode *node = root;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      ans.push_back((vector<int>()));
      for (int i = 0; i < levelSize; i++) {
        node = q.front();
        q.pop();
        ans.back().push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return ans;
  }
  // 34
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    stack<TreeNode *> q;
    stack<TreeNode *> tmp;
    // must handle nullptr condition
    if (root == nullptr)
      return ans;
    
    TreeNode *node = root;
    q.push(root);
    bool direction = true;

    while (!q.empty()) {
      int levelSize = q.size();
      ans.push_back((vector<int>()));
      for (int i = 0; i < levelSize; i++) {
        node = q.top();
        q.pop();
        ans.back().push_back(node->val);
        if (direction) {
          if (node->left)
            tmp.push(node->left);
          if (node->right)
            tmp.push(node->right);
        } else {
          if (node->right)
            tmp.push(node->right);
          if (node->left)
            tmp.push(node->left);
        }
      }
      q = std::move(tmp);
      direction = !direction;
    }
    return ans;
  }
};



int main() {
  Solution sol;
  vector<vector<int>> ans;

  vector<int> ex1 = {1, 2, 3, 0, 0, 4, 5};
  TreeNode *head = createTree(ex1);
  ans = sol.levelOrder(head);
  display(ans);
  deleteTree(head);
  return 0;
}