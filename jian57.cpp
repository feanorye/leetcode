#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "listnode.h"


using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
public:
  // 超时
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> dp;
        vector<int> ans;
        for(auto x : nums){
            if( x > target)
                break;
            for(int i = 0; i < dp.size(); i++){
                if(dp[i] == x){
                    ans.push_back(nums[i]);
                    ans.push_back(x);
                    return ans;
                }
            }
            dp.push_back(target - x);
        }
        return ans;
    }
    vector<int> twoSum(vector<int> &nums, int target) {
      int i = 0, j = nums.size() - 1;
      vector<int> ans;
      while (i < j) {
        if (target - nums[i] > nums[j]) {
          i++;
          continue;
        }
        if (target - nums[i] < nums[j]) {
          j--;
          continue;
        }
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        return ans;
      }
      return ans;
    }

};

int main() {
  Solution sol;
  vector<int> ex1 = {10, 26, 30, 31, 47, 60};
  printV(sol.twoSum(ex1, 40));
}