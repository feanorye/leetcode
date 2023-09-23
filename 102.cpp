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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<TreeNode *> cur, nxt;
    vector<vector<int>> ans;
    if (root == nullptr)
      return {};
    cur.push_back(root);
    while (true) {
      vector<int> layer;
      TreeNode *l;
      int len = cur.size();
      for(int i = 0; i < len; i++) {
        l = cur[i];
        layer.push_back(l->val);
        if (l->left != nullptr) {
          nxt.push_back(l->left);
        }
        if (l->right != nullptr) {
          nxt.push_back(l->right);
        }
      }

      ans.emplace_back(std::move(layer));
      if (nxt.empty()) {
        break;
      } else {
        cur = std::move(nxt);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}