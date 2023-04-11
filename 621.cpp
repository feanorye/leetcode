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
  int leastInterval(vector<char> &tasks, int n) {
    int ans = 0;
    map<char, int> hash;
    for (auto c : tasks) {
      hash[c]++;
    }
    int cnt = 0, maxv = 0;
    for (auto [k, v] : hash) {
      if (maxv < v) {
        cnt = 1;
        maxv = v;
        continue;
      }
      if (maxv == v) {
        cnt++;
      }
    }
    return std::max((n+1)*(maxv-1)+cnt, (int)tasks.size());
  }
};

int main() {
  Solution sol;
  return 0;
}