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

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
//     [-1,-1,0]
    int maximumCount(vector<int>& nums) {
        size_t len = nums.size();
        size_t cnt = -1, cnt2 = -1;
        for(int i = 0; i < len; i++){
            if(nums[i] >= 0 && cnt == -1){
                cnt = i;
            }
            if(nums[i] > 0){
                cnt2 = i;
                break;
            }
        }
        if(cnt2 == -1)
            cnt2 = len;
        return max(cnt, len - cnt2);
    }
};

int main() {
  Solution sol;
  vector<int> ex1 = {-1, -1, 0};
  printInt("ans: 2 --", sol.maximumCount(ex1));
  return 0;
}