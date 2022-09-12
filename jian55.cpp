#include <algorithm>
#include <exception>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "tree.h"


using std::cout;
using std::endl;
using std::max;
using std::min;
using std::queue;
using std::string;
using std::vector;

class Solution {
public:
    int maxDepth(TreeNode* root) {
      queue<TreeNode *> st;
      queue<TreeNode *> st2;
      int level = 0;
      st.push(root);
      while (!st.empty()) {
        TreeNode *node = st.front();
        st.pop();
        if (node->left)
          st2.push(node->left);
        if (node->right)
          st2.push(node->right);
        if (st.empty()) {
          level++;
          st = std::move(st2);
        }
      }
      return level;
    }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}