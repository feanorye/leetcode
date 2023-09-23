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
private:
  int ans;
  /**
   * fixme: return的值怎么确定的？
   * @return: 以当前节点为连接点，能够连接的单方向边个数，以供父节点连接。
   *          故，不可用边和null节点都应返回-1，在加边过程中抵消
   */
  int postOrder(TreeNode *root) {
    if (root == nullptr) {
      return -1;
    }
    int lans = postOrder(root->left);
    int rans = postOrder(root->right);
    if (root->left != nullptr && root->val != root->left->val) {
      lans = -1;
    }
    if (root->right != nullptr && root->val != root->right->val) {
      rans = -1;
    }
    // update ans: connect left + node + right
    ans = max(ans, lans + rans + 2);
    return max(lans, rans) + 1;
  }
public:
  /* 最长相同节点组成的路径长度，即为边的个数
  */
  int longestUnivaluePath(TreeNode *root) {
    ans = 0;
    postOrder(root);
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}