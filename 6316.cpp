#include "listnode.h"
#include <algorithm>
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
  int maxScore(vector<int> &nums) {
    sort(nums.begin(), nums.end(), std::greater<int>());
    auto n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
      // prefix[i] == sum[:i]
      prefix[i + 1] = prefix[i] + nums[i];
      if (prefix[i + 1] < 0)
        return i;
    }
    return n;
  }
};

int main() {
  Solution sol;
  return 0;
}