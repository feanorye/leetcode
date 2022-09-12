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
  vector<int> path;

  vector<vector<int>> pathSum(TreeNode *root, int target) {
    vector<vector<int>> ans;
    Dfs(root, target, ans);
    return ans;
  }
  void Dfs(TreeNode *root, int target, vector<vector<int>> &ans) {
    if (root == nullptr)
      return;
    target -= root->val;
    path.push_back(root->val);
    // leef node
    if (!root->left && !root->right && target == 0) {
      ans.push_back(path);
    }
    if (root->left)
      Dfs(root->left, target, ans);
    if (root->right)
      Dfs(root->right, target, ans);

    //回退
    path.pop_back();
    return;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  ex1.emplace_back(Args && args...);
  return 0;
}