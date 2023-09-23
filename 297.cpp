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
  void serialize_helper(TreeNode *root, string &ans) {
    if (root == nullptr) {
      ans += "N,";
      return;
    }
    ans += std::to_string(root->val) + ",";
    serialize_helper(root->left, ans);
    serialize_helper(root->right, ans);
  }
  TreeNode *deserialize_helper(string &data, int &pos, int len) {
    if (data[pos] == 'N') {
      pos += 2;
      return nullptr;
    }
    int val = 0;
    int mode = 1;
    for (; pos < len; pos++) {
      if (data[pos] == ',') {
        pos++;
        break;
      }
      val = val * 10 + data[pos] - '0';
    }
    TreeNode *node = new TreeNode(val);
    node->left = deserialize_helper(data, pos, len);
    node->right = deserialize_helper(data, pos, len);
    return node;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans;
    serialize_helper(root, ans);
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int len = data.size();
    int pos = 0;
    return deserialize_helper(data, pos, len);
  }
};

int main() {
  Solution sol;
  vector<int> ex3{-1,        -2, 10,        -6, INT32_MIN, -3,       -6,
                  INT32_MIN, 7,  INT32_MIN, 9,  10,        INT32_MIN};
  auto root3 = Create_tree(ex3);
  cout << "ans: " << sol.serialize(root3) << endl;
  return 0;
}