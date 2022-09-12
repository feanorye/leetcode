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

class Solution {
private:
  /* @ l: inorder left
  *  @ r: inorder right
  *
  *
  */
  TreeNode *recur(int l, int r, int head, vector<int> &pre, vector<int> &ino) {
    if (l == r)
      return nullptr;
    // root: node root val
    int root = pre[head];
    TreeNode *ans = new TreeNode(root);
    int i = l;
    for (; i < r; i++) {
      if (ino[i] == root)
        break;
    }
    // create left tree
    TreeNode *lchild = recur(l, i, head + 1, pre, ino);
    TreeNode *rchild = recur(i + 1, r, head + i - l + 1, pre, ino);
    ans->left = lchild;
    ans->right = rchild;
    return ans;
  }
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int len = inorder.size();
    TreeNode * ans = recur(0, len, 0, preorder, inorder);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}