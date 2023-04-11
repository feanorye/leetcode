#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
#include <functional>
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
  // [3,1,2], [4,3,1,2,4],
  long long beautifulSubarrays(vector<int> &nums) {
    int ans = 0;
    auto n = nums.size();
    int presum = 0;
    std::unordered_map<int, int> hash;
    hash[0]++;
    for (size_t i = 0; i < n; i++) {
      presum = presum ^ nums[i];
      ans += hash[presum]++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {3, 1, 2};
  printInt("ans: 1 -- ", sol.beautifulSubarrays(ex1));
  vector<int> ex2 = {4, 3, 1, 2, 4};
  printInt("ans: 2 -- ", sol.beautifulSubarrays(ex2));
  return 0;
}