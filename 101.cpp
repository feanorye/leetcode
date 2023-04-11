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
  bool isSymmetric(TreeNode *root) {
    vector<TreeNode *> st_c, st_nxt;
    queue<TreeNode *> q_c, q_nxt;
    if (root->right != nullptr)
      st_c.push_back(root->right);
    if (root->left != nullptr)
      q_c.push(root->left);

    if (q_c.size() != st_c.size())
      return false;

    while (!q_c.empty()) {
      TreeNode *left_t = q_c.front(), *right_t = st_c.back();
      q_c.pop();
      st_c.pop_back();

      if (left_t == nullptr && right_t != nullptr) {
        return false;
      } else if (left_t != nullptr && right_t == nullptr) {
        return false;
      } else if (left_t != nullptr && right_t != nullptr && left_t->val != right_t->val) {
        return false;
      }
      if (left_t != nullptr) {
        q_nxt.push(left_t->left);
        q_nxt.push(left_t->right);
      }
      if (right_t != nullptr) {
        st_nxt.push_back(right_t->right);
        st_nxt.push_back(right_t->left);
      }

      if (q_c.empty()) {
        q_c = std::move(q_nxt);
        std::reverse(st_nxt.begin(), st_nxt.end());
        st_c = std::move(st_nxt);
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  TreeNode *root = nullptr;
  vector<int> ex2 = {9, 76, 76, -4, -1, -1, -4, 26, -61, -61, -21};
  root = Create_tree(ex2);
  sol.isSymmetric(root);
  vector<int> ex1 = {1, 2, 2, -1, 3, -1, 3};
  root = Create_tree(ex1);
  sol.isSymmetric(root);
  return 0;
}