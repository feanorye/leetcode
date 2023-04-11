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
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
  
        sort(nums.begin(), nums.end());
        size_t len = nums.size();
        vector<int> preSum(len+1, 0);
        for(int i =1; i <= len; i++){
            preSum[i] = preSum[i-1]+nums[i-1];
        }
        vector<long long> ans;
        for(auto q : queries){
            auto it = lower_bound(nums.begin(), nums.end(), q);
            int low = distance(nums.begin(), it);
            long long tmp = preSum[len] - 2*preSum[low] + q *(2*low - len);
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
  Solution sol;
  vector<int> ex1 = {3, 1, 6, 8};
  vector<int> q1 = {1, 5};
  printV(sol.minOperations(ex1, q1), "ans: [14,10]");
  return 0;
}