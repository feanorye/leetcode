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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *findBT(TreeNode *root, int val) {
  TreeNode *ans;
  if (root == nullptr)
    return nullptr;
  if (val < root->val)
    ans = findBT(root->left, val);
  else
    ans = findBT(root->right, val);
  if (ans == nullptr)
    ans = root;
  return ans;
}
TreeNode *createBinaryTree(vector<int> &arr) {
  int len = arr.size();
  if (len == 0)
    return nullptr;
  TreeNode *root = new TreeNode(arr[0]);
  for (int i = 1; i < len; i++) {
    TreeNode *insertP = findBT(root, arr[i]);
    if (arr[i] < insertP->val)
      insertP->left = new TreeNode(arr[i]);
    else
      insertP->right = new TreeNode(arr[i]);
  }
  return root;
}

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
// display matrix
void display(vector<vector<int>> &arr) {
  for (auto row : arr) {
    for (auto num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
}