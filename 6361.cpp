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
  // 对角线质数
  int diagonalPrime(vector<vector<int>> &nums) {
    int len = nums.size();
    int ans = 0;
    auto is_prime = [](int x) -> bool {
      if (x < 2)
        return false;
      for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
          return false;
      }
      return true;
    };
    for (int r = 0; r < len; r++) {
      if (nums[r][r] > ans && is_prime(nums[r][r]))
        ans = nums[r][r];
      if (nums[r][len - 1 - r] > ans && is_prime(nums[r][len - 1 - r]))
        ans = nums[r][len-1-r];
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {
      {367, 941, 856, 950, 80, 419},  {56, 452, 364, 619, 924, 636},
      {775, 262, 689, 318, 577, 870}, {824, 465, 423, 186, 32, 465},
      {822, 271, 196, 973, 397, 66},  {367, 99, 127, 27, 360, 22}};
  printInt("ans: 111 -", sol.diagonalPrime(ex2));
  vector<vector<int>> ex1 = {{1, 2, 3}, {5, 17, 7}, {9, 11, 10}};
  sol.diagonalPrime(ex1);
  return 0;
}