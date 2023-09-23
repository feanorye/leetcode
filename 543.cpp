#include "listnode.h"
#include <algorithm>
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
  // @return: depth of tree
  int postOrder(TreeNode *root, int &ans) {
    int d1{0}, d2{0};
    if (root->left != nullptr) {
      d1 = postOrder(root->left, ans);
    }
    if (root->right != nullptr) {
      d2 = postOrder(root->right, ans);
    }
    ans = max(ans, d1 + d2);
    return max(d1, d2) + 1;
  }
  // 树内节点的最远距离
  int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    postOrder(root, ans);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1{1,2,3,4,5};
  auto root = Create_tree(ex1);
  printInt("ans: 3--", sol.diameterOfBinaryTree(root));
  
  return 0;
}