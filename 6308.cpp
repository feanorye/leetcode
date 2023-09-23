#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <tuple>

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
using std::priority_queue;

class Solution {
public:
  // todo: 溢出
      long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<int> pq;
        queue<TreeNode*> q, qc;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            auto elem = q.front(); q.pop();
            if(elem->right != nullptr)
              qc.push(elem->right);
            if (elem->left != nullptr)
              qc.push(elem->left);
            
            sum += elem->val;
            if (q.empty()) {
              q = std::move(qc);
              pq.push(sum);
              sum = 0;
            }
        }
        
        if(pq.size() < k)
            return -1;
        int i = 1;
        while(i++ < k){
            pq.pop();
        }

        sum = pq.top();
        pq.pop();
        return sum;
}
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}