#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <tuple>
#include <type_traits>
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
  void helper(vector<vector<int>> &res, vector<int> &tmp, int r_size,
              vector<int> &nums, vector<int> &is_add, const int &n) {
    if (r_size == n) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (is_add[i] == 0) {
        is_add[i] = 1;
        tmp.push_back(nums[i]);
        helper(res, tmp, r_size + 1, nums, is_add, n);
        tmp.pop_back();
        is_add[i] = 0;
      }
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    auto n = nums.size();
    vector<vector<int>> ans;
    vector<int> is_add(n, 0);
    vector<int> tmp;
    helper(ans, tmp, 0, nums, is_add, n);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 2, 3};
  printl(sol.permute(ex1));
  return 0;
}