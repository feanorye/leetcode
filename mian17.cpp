#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include "listnode.h"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class Solution {
public:
  vector<int> missingTwo(vector<int> &nums) {
    int len = nums.size();
    long sum = 0;
    for (auto x : nums) {
      sum += x;
    }
    long real_sum = (len + 2) * (1 + len + 2) / 2;
    long two_sum = real_sum - sum;
    long flag = (two_sum) / 2;
    long t = flag * (1 + flag) / 2;
    for (auto x : nums) {
      if (x <= flag)
        t -= x;
    }
    vector<int> ans;
    ans.push_back(t);
    ans.push_back(two_sum - t);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 2, 3, 4, 6, 7, 9, 10};
  printV(sol.missingTwo(ex1),"ans: [5, 8]");
  return 0;
}