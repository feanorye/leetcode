#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>


using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
using std::set;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
      set<int> rep;
      int ma = nums[0];
      int mi = nums[0];
      for (auto x : nums) {
        if (x == 0)
          continue;
        ma = max(ma, x);
        mi = min(x, mi);
        if (rep.count(x) != 0)
          return false;
        rep.insert(x);
      }
      return ma - mi < 5;
    }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}