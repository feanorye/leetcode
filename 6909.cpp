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
  int longestAlternatingSubarray(vector<int> &nums, int threshold) {
    int l = -1;
    int ans = 0;
    int len = nums.size();

    for (int r = 0; r < len; r++) {
      if (l == -1) {
        if (nums[r] <= threshold && nums[r] % 2 == 0) {
          l = r;
        }
      } else if (nums[r] > threshold || nums[r] % 2 == nums[r - 1] % 2) {
        ans = max(ans, r - l);
        l = -1;
        r--;
      }
    }
    if (l != -1 && nums[len - 1] <= threshold) {
      ans = max(ans, len - l);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex8{8, 4};
  printInt("ans: 1 -- ", sol.longestAlternatingSubarray(ex8, 6));
  vector<int> ex7{2, 2};
  printInt("ans: 1 -- ", sol.longestAlternatingSubarray(ex7, 12));
  vector<int> ex6{1, 3};
  printInt("ans: 0 -- ", sol.longestAlternatingSubarray(ex6, 12));
  vector<int> ex5{2, 8};
  printInt("ans: 1 -- ", sol.longestAlternatingSubarray(ex5, 4));
  vector<int> ex4{1};
  printInt("ans: 0 -- ", sol.longestAlternatingSubarray(ex4, 1));
  vector<int> ex3{2, 3, 4, 5};
  printInt("ans: 3 --", sol.longestAlternatingSubarray(ex3, 4));
  vector<int> ex2{1, 2};
  printInt("ans: 1 -- ", sol.longestAlternatingSubarray(ex2, 2));
  vector<int> ex1{3, 2, 5, 4};
  printInt("ans: 3 -- ", sol.longestAlternatingSubarray(ex1, 5));
  return 0;
}