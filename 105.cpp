#include "listnode.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // pl, il作为起点，pr,ir不可访问的右边界
    std::function<TreeNode *(int, int, int, int)> build =
        [&](int pl, int pr, int il, int ir) -> TreeNode * {
      if (pl >= pr || il >= ir) {
        return nullptr;
      }
      int x = preorder[pl];
      TreeNode *node = new TreeNode(x);
      int i = il;
      for (; i < ir; i++) {
        if (inorder[i] == x)
          break;
      }
      int cnt = i - il;
      // 先序遍历左边界加一，表示子树可不取到根值
      node->left = build(pl + 1, pl + cnt + 1, il, i);
      // 中序遍历左边界加一，表示右子树不可取到根值
      node->right = build(pl + cnt + 1, pr, i+1, ir);
      return node;
    };
    TreeNode *root;
    int len = preorder.size();
    root = build(0, len, 0, len);
    return root;
  };
};

int main() {
  Solution sol;
  vector<int> ex1 = {3, 9, 20, 15, 7};
  vector<int> ex2 = {9, 3, 15, 20, 7};
  auto root = sol.buildTree(ex1, ex2);
  pre_tree(root);
  return 0;
}