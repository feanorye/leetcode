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
public:
  int kthLargest(TreeNode *root, int k) { return dfs(root, k); }
  int dfs(TreeNode *root, int &k) {
    int ans;
    if (root == nullptr)
      return -1;
    if (root->right) {
      ans = dfs(root->right, k);
      if (k == 0)
        return ans;
    }
    if ((--k) == 0)
      return root->val;
    if (root->left) {
      ans = dfs(root->left, k);
      if (k == 0)
        return ans;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}