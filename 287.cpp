#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include <queue>
#include<set>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
public:
  // wrong: o(1) space
    int findDuplicate2(vector<int>& nums) {
      std::set<int> mem;
      for (auto k : nums) {
        if (mem.count(k) != 0)
          return k;
        mem.insert(k);
      }
      return false;
    }
    int findDuplicate(vector<int> &nums) {
      int len = nums.size();
      
    }
};
int main() {
    Solution sol;
}