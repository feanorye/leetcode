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
  // 找出可被最多元素整除的divisor
  int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    map<int, int> hash, numcnt;
    std::sort(nums.begin(), nums.end());
    for (int e : nums) {
      numcnt[e]++;
    }
    int pre = -1;
    for (int e : nums) {
      if (e == pre) {
        continue;
      }
      // 4: [1,4]
      int i = 1;
      for (; i * i < e; i++) {
        if (e % i == 0) {
          hash[i] += numcnt[e];
          hash[e / i] += numcnt[e];
        }
      }
      if (e % i == 0)
        hash[i] += numcnt[e];
      pre = e;
    }
    int ans = -1, ret = -1;
    for (int d : divisors) {
      if (hash[d] > ans) {
        ret = d;
        ans = hash[d];
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {
      {56, 22, 79, 41, 8, 39, 81, 59, 74, 14, 45, 49, 15, 10, 28,
       16, 77, 22, 65, 8, 36, 79, 94, 44, 80, 72, 8,  96, 78},
      {39, 92, 69, 55, 9,  44, 26, 76, 40, 77, 16, 69, 40, 64,
       12, 48, 66, 7,  59, 10, 33, 72, 97, 60, 79, 68, 25, 63}};
  printInt("ans: 5 -- ", sol.maxDivScore(ex1[0], ex1[1]));
  return 0;
}