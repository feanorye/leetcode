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
#include <unordered_set>
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
  /* queries[i] = [typei, indexi, vali]
  ** typei = 0: change row[indexi] to vali
  ** typei = 1: change col[indexi] to vali */
  long long matrixSumQueries(int n, vector<vector<int>> &queries) {
    // 反向：新值不会被旧值覆盖
    long long ans = 0;
    std::unordered_set<int> vis[2]; // [row_set, col_set]
    int len = queries.size();
    for (int i = len - 1; i >= 0; i--) {
      vector<int> &query = queries[i];
      int type = query[0];
      int idx = query[1];
      int val = query[2];
      if (!vis[type].count(idx)) {
        ans += (long long)(n - vis[type ^ 1].size()) * val;
        vis[type].insert(idx);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{0, 0, 1}, {1, 2, 2}, {0, 2, 3}, {1, 0, 4}};
  cout << "ans: 23 -- " << sol.matrixSumQueries(3, ex1) << endl;
  return 0;
}