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
  vector<vector<int>> findMatrix(vector<int> &nums) {
    vector<vector<int>> ans;
    map<int, int> hash1, hash2;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size();) {
      int j = i + 1;
      while (j < nums.size() && nums[j] == nums[i]) {
        j++;
      }
      hash1[nums[i]] = j - i;
      i = j;
    }
    while (!hash1.empty()) {
      vector<int> ans_v;
      for (auto [k, v] : hash1) {
        ans_v.push_back(k);
        if (v - 1 > 0)
          hash2[k] = v - 1;
      }
      ans.push_back(ans_v);
      hash1 = std::move(hash2);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}