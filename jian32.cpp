#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::queue;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> levelOrder(TreeNode *root) {
    vector<int> ans;
    std::queue<TreeNode *> q;
    // must handle nullptr condition
    if (root == nullptr)
      return ans;
    TreeNode *node = root;
    q.push(root);
    while (!q.empty()) {
      node = q.front();
      q.pop();
      ans.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    return ans;
  }
};

TreeNode *createTree(vector<int> &arr) {
  TreeNode *head = nullptr;
  TreeNode *p = nullptr;
  queue<TreeNode *> q;
  int n = arr.size();
  if (n == 0)
    return head;

  head = new TreeNode(arr[0]);
  q.push(head);
  TreeNode *ln, *rn;
  for (int i = 1; i < n; i += 2) {
    rn = nullptr;
    ln = nullptr;
    if (arr[i]) {
      ln = new TreeNode(arr[i]);
      q.push(ln);
    }
    if ((i + 1) < n && arr[i + 1]) {
      rn = new TreeNode(arr[i + 1]);
      q.push(rn);
    }
    p = q.front();
    q.pop();
    p->left = ln;
    p->right = rn;
  }
  return head;
}
int deleteTree(TreeNode *head) {
  if (head->left) {
    deleteTree(head->left);
  }
  if (head->right)
    deleteTree(head->right);
  delete head;
  return 0;
}

int main() {
  Solution sol;
  vector<int> ex1 = {};
}