#include "tree.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;

typedef TreeNode Node;
class Solution {
public:
  Node *head;
  Node *pre;
  Node *treeToDoublyList(Node *root) {
    head = nullptr;
    pre = nullptr;
    if (root == nullptr)
      return nullptr;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
  }
  void dfs(Node *root) {
    if (root == nullptr)
      return;
    dfs(root->left);
    if (pre == nullptr) {
      head = root;
      pre = root;
    } else {
      pre->right = root;
      root->left = pre;
      pre = root;
    }
    dfs(root->right);
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {4, 2, 5, 1, 3};
  TreeNode *root = createBinaryTree(ex1);
  sol.treeToDoublyList(root);
  deleteTree(root);
  return 0;
}