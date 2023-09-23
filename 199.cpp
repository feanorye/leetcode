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
  // 返回最靠右侧的元素
  //      6
  //   5      9
  // 2      7
  //  3
  vector<int> rightSideView(TreeNode *root) {
    // BFS: 层序遍历
    if (root == nullptr)
      return {};
    vector<int> ans;
    TreeNode *p = root;
    queue<TreeNode *> q, nxtq;
    q.push(root);
    
    while (!q.empty()) {
      p = q.front();
      q.pop();
      if (p->left != nullptr) {
        nxtq.push(p->left);
      }
      if (p->right != nullptr) {
        nxtq.push(p->right);
      }
      if (q.empty()) {
        ans.push_back(p->val);
        q = std::move(nxtq);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}