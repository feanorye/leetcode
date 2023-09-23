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
  // topK问题：1. 维护最高的k个元素
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // 桶排序
    vector<int> ans;
    std::unordered_map<int, int> umap;
    int maxcnt = 0;
    for (int e : nums) {
      maxcnt = max(++umap[e], maxcnt);
    }
    vector<vector<int>> bucket(maxcnt + 1);
    for (auto [k, v] : umap) {
      bucket[v].push_back(k);
    }
    for (int i = maxcnt; i > 0; i--) {
      ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
    }
    return {ans.begin(), ans.begin()+k};
  }
};

int main() {
  Solution sol;
  return 0;
}