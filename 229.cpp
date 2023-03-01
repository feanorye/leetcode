#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  // find all element which appears more than n/3 times
  vector<int> majorityElement(vector<int> &nums) {
    int k = 3, n = nums.size();
    vector<int> candiate(k - 1, -1);
    vector<int> count(k - 1, 0);
    for (auto e : nums) {
      int zero_ind = -1;
      int find_same = -1;
      for (int i = 0; i < k - 1; i++) {
        if (e == candiate[i]) {
          find_same = 1;
          count[i]++;
          break;
        }
        if (count[i] == 0)
          zero_ind = i;
      }
      if (find_same == 1)
        continue;
      if (zero_ind == -1) {
        for (int i = 0; i < k - 1; i++) {
          if (count[i] > 0)
            count[i]--;
        }
      } else {
        candiate[zero_ind] = e;
        count[zero_ind] = 1;
      }
    }
    vector<int> ans;
    count = vector<int>(k - 1, 0);
    for (auto e : nums)
      for (int i = 0; i < k - 1; i++) {
        if (e == candiate[i]) {
          count[i]++;
          break;
        }
      }
    for (int i = 0; i < k - 1; i++) {
      if (count[i] > n / k)
        ans.push_back(candiate[i]);
    }
    return ans;
  }
  vector<int> majorityElement2(vector<int> &nums) {
    map<int, int> hash;
    vector<int> ans;
    for (auto e : nums)
      hash[e]++;
    for (auto e : hash)
      if (e.second > (nums.size() / 3))
        ans.push_back(e.first);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex4 = {-1,-1,-1};
  printV(sol.majorityElement(ex4), "ans: -1 -- ");
  vector<int> ex3 = {3, 2, 3};
  printV(sol.majorityElement(ex3), "ans: 3 -- ");
  vector<int> ex2 = {2, 2};
  printV(sol.majorityElement(ex2), "ans: 2 -- ");
  vector<int> ex1 = {1, 2};
  printV(sol.majorityElement(ex1), "ans: 1,2 -- ");
  return 0;
}