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
  int InOrder(TreeNode *root, int val) {
    if (root->right) {
      val = InOrder(root->right, val);
    }
    val += root->val;
    root->val = val;
    if (root->left) {
      val = InOrder(root->left, val);
    }
    return val;
  }

public:
  TreeNode *convertBST(TreeNode *root) {
    if (root != nullptr) {
      InOrder(root, 0);
    }
    return root;
  }
};

int main() {
  Solution sol;
  return 0;
}