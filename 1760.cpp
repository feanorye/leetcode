#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
class Solution {
public:
  // lc: given maxOperation, get max ball.
  int minimumSize(vector<int> &nums, int maxOperations) {
    // y: max bag ball number.
    // problem could be changed to change ballnumber, get new operation num,
    // check satisfication.
    int y = *std::max_element(nums.begin(), nums.end());
    int l = 1, r = y;
    while (l < r) {
      int m = l + (r - l) / 2;
      int ops = 0;
      for (auto v : nums) {
        ops += (v - 1) / m;
      }
      // check only 2 elem, new m must could be changed.
      if (ops <= maxOperations) { // operation to little, so turn down y
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
int main() {
  Solution sol;
  vector<int> ex1 = {9};
  cout << sol.minimumSize(ex1, 2);
}