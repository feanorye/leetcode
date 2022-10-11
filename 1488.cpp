#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
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
using std::set;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    int n = rains.size();
    set<int> zeros; // 存储为0的序号
    vector<int> ans(n, 1);
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
      int ele = rains[i];
      if (ele == 0) {
        zeros.insert(i);
        continue;
      }
      if (hash.count(ele) != 0) {
        auto it = zeros.lower_bound(hash[ele]);
        if (it == zeros.end())
          return {};
        ans[*it] = ele;
        zeros.erase(it);
      }
      hash[ele] = i;
      ans[i] = -1;
    }
    return ans;
  }
  //超时
  vector<int> avoidFlood2(vector<int> &rains) {
    int n = rains.size();
    vector<int> ans(n, -1);
    map<int, int> hash;
    int l = 0;
    for (int r = 0; r < n; r++) {
      if (rains[r] > 0) {
        if (hash.count(rains[r]) != 0) {
          l = hash[rains[r]];
          while ((l < r && rains[l] != 0) || ans[l] != -1)
            l++;
          if (l >= r) {
            return vector<int>();
          }

          ans[l++] = rains[r];
          hash[rains[r]] = r;
        } else {
          hash[rains[r]] = r;
        }
      }
    }
    l = 0;
    while (l < n) {
      if (rains[l] == 0 && ans[l] == -1)
        ans[l] = 1;
      l++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex4 = {0, 1, 1};
  printV(sol.avoidFlood(ex4), "ans: [] -- ");
  vector<int> ex3 = {1, 2, 3, 4};
  printV(sol.avoidFlood(ex3), "ans: [-1,-1,-1,-1] -- ");
  vector<int> ex2 = {1, 2, 0, 1, 2};
  printV(sol.avoidFlood(ex2), "ans: [] -- ");
  vector<int> ex1 = {1, 0, 1, 2};
  printV(sol.avoidFlood(ex1), "ans: [-1,1,-1,-1] -- ");
  return 0;
}