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
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    // 关键步骤：排序为之后去重做准备
    std::sort(candidates.begin(), candidates.end());
    dfs(0, target, candidates, path, res);
    return res;
  }
  void dfs(int start, int target, vector<int> &candidates, vector<int> &path,
           vector<vector<int>> &res) {
    if (target < 0)
      return;
    if (target == 0) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size(); i++) {
      // 已排序，若当前target - [i] < 0, [i:]皆会如此
      if ((target - candidates[i]) < 0)
        break;
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      path.push_back(candidates[i]);
      dfs(i + 1, target - candidates[i], candidates, path, res);
      path.pop_back();
    }
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {2, 5, 2, 1, 2};
  printl(sol.combinationSum2(ex2, 5));
  vector<int> ex1 = {10, 1, 2, 7, 6, 1, 5};
  printl(sol.combinationSum2(ex1, 8));
  return 0;
}