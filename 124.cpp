#include "listnode.h"
#include <algorithm>
#include <iostream>
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
private:
  /**
   * @return {choose, notChoose}
   */
  pair<int, int> postOrder(TreeNode *root) {
    pair<int, int> left{0, INT32_MIN};
    pair<int, int> right{0, INT32_MIN};
    if (root->left) {
      left = postOrder(root->left);
    }
    if (root->right) {
      right = postOrder(root->right);
    }

    int val = root->val;
    int choose = max(val, val + max(left.first, right.first));
    int notchoose = val + left.first + right.first;
    int noti = INT32_MIN;
    if (root->left != nullptr || root->right != nullptr) {
      notchoose = max(notchoose, max(left.second, right.second));
    }
    if (root->left != nullptr) {
      noti = max(left.first, left.second);
    }
    if (root->right != nullptr) {
      noti = max(noti, max(right.first, right.second));
    }
    notchoose = max(noti, notchoose);
    return {choose, notchoose};
  }

public:
  /*最大路径长度*/
  int maxPathSum(TreeNode *root) {
    /*
    后序遍历
                +--- -1 ---+
                |          |
                -2     +---10----+
                       |         |
                      -4         -3
      1. dp[0]: nodei
      2. dp[1]: nodei + max{left0, right0}
      3. dp[2]: nodei + left0 + right0
      4. dp[3]: max{left0, left1, right0, right1}: could fail if node dont have 2 children
    边界：leaf:{val, val}
    => parent could choose    : max[1,2]
    => parent couldn't choose : max[3,4]
    => left0 = max{dp[0], dp[1]},
       left1 = max{nodei + left0+ right0,
                   max{left0, left1, right0, right1} }
     */
    auto res = postOrder(root);
    // todo: 理解下dfs解法？似乎比我想的简单
    return max(res.first, res.second);
  }
};

int main() {
  Solution sol;
  vector<int> ex3{-1, -2, 10, -6, INT32_MIN, -3, -6};
  auto root3 = Create_tree(ex3);
  printInt("and: 10 -- ", sol.maxPathSum(root3));

  vector<int> ex2 = {-2, -1};
  auto root = Create_tree(ex2);
  printInt("ans: -1 -- ", sol.maxPathSum(root));
  vector<int> ex1 = {-3};
  auto root2 = Create_tree(ex1);
  printInt("ans: -3 -- ", sol.maxPathSum(root2));

  return 0;
}