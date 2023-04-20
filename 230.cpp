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
    int traverse(TreeNode *root, int &level, int k){
        int ans;
        if(root->left){
            ans = traverse(root->left, level, k);
            if(level >= k)
                return ans;
        }
        level++;
        if(level >= k)
            return root->val;
        if(root->right){
            ans = traverse(root->right, level, k);
        }   
        return ans;
    }
    // 二叉搜索树第k小的数字
    int kthSmallest(TreeNode* root, int k) {
        int level = 0;
        int ans = traverse(root, level, k);
        return ans;
    }
};

int main() {
  Solution sol;
  vector<int> ex1 = {5,3,6,2,4,-1,-1,1};
  TreeNode *root = Create_tree(ex1);
  printInt("ans: 3 -- ", sol.kthSmallest(root, 3));
  return 0;
}