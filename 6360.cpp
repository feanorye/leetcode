#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
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
  vector<long long> distance(vector<int> &nums) {
    int len = nums.size();
    vector<long long> ans(len, 0);
    map<int,vector<int>> hash;
    for (int i = 0; i < len; i++) {
      hash[nums[i]].push_back(i);
    }
    for (int i = 0; i < len; i++) {
      auto &v = hash[nums[i]];
      long long dif = 0;
      for (auto e : v) {
        dif +=abs(i-e);
      }
      ans[i] = dif;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}