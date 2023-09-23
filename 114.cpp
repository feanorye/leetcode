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
  // 后序遍历：返回子树tail
  TreeNode *post_trav(TreeNode *head) {
    TreeNode *ltail = nullptr, *rtail = nullptr;
    if (head->left) {
      ltail = post_trav(head->left);
    }
    if (head->right) {
      rtail = post_trav(head->right);
    }
    // 叶节点
    if (ltail == nullptr && rtail == nullptr) {
      return head;
    }
    // 左子树存在
    if (ltail != nullptr) {
      ltail->right = head->right;
      head->right = head->left;
      head->left = nullptr;
    }
    return rtail == nullptr ? ltail : rtail;
  }
  // 将树展开为链表，先序遍历顺序，右指针作为next
  void flatten(TreeNode *root) {
    // 后序遍历
    if (root == nullptr) {
      return;
    }
    post_trav(root);
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1,2,5,3,4,-1,6};
  TreeNode *head = Create_tree(ex1);
  pre_tree(head);
  sol.flatten(head);
  pre_tree(head);
  return 0;
}