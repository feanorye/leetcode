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
  // 等值距离和：nums[i] 和所有相同元素的序列之差的绝对和
    vector<long long> distance(vector<int>& nums) {
      size_t len = nums.size();
      map<int,vector<int>> hash;
      for (int i = 0; i < len; i++) {
        hash[nums[i]].push_back(i);
      }
      vector<long long> presum(len+1, 0);
      vector<long long> arr(len, 0);
      for (auto &[_, v] : hash) {
        for (int i = 1; i <= v.size(); i++) {
          presum[i] = presum[i-1] + v[i-1];
        }
        int n = v.size();
        for (int i = 0; i < n; i++) {
         arr[v[i]] =  presum[n] - 2 * presum[i] + v[i] * (i * 2 - n);
        }
      }
      return arr;
}
};

int main() {
  Solution sol;
  vector<int> ex2 = {1};
  printV(sol.distance(ex2), "ans: [0] -- ");
  vector<int> ex1 = {1, 3, 1, 1, 2};
  printV(sol.distance(ex1), "ans: [5,0,3,4,0] -- ");
  return 0;
}