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
  // top-k问题: 获得k个最高频次的元素
  //            1. 大顶堆 2. 桶排序
  // 相等频次，按照字典顺序排序
  vector<string> topKFrequent(vector<string> &words, int k) {
    std::unordered_map<string, int> umap;
    for (string &s : words) {
      umap[s]++;
    }
    auto compare = [](pair<string, int> &l, pair<string, int> &r) {
      if (l.second != r.second) {
        return l.second > r.second; //频次较低，先出
      }
      return l.first < r.first; //字典序靠后，先出
    };
    std::priority_queue<pair<string, int>, vector<pair<string, int>>,
                        decltype(compare)>
        pq(compare);
    for (auto [key, val] : umap) {
      pq.emplace(key, val);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<string> ans;
    while (!pq.empty()) {
      ans.emplace_back(pq.top().first);
      pq.pop();
    }
    return {ans.rbegin(), ans.rend()};
  }
};

int main() {
  Solution sol;
  return 0;
}