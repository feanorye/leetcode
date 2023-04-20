#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
  bool traverse(TreeNode *root, long &pre) {
    if (root->left && !traverse(root->left, pre)) 
      return false;
    if (pre >= root->val)
      return false;
    // 赋值为当前值
    pre = root->val;
    if (root->right && !traverse(root->right, pre))
      return false;
    return true;
  }
  bool isValidBST(TreeNode *root) {
    long pre{LONG_MIN};
    return traverse(root, pre);
  }
};

int main() {
  Solution sol;
  return 0;
}