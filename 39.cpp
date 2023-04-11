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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> path;
      dfs(0, target, candidates, path, res);
      return res;
    }
    void dfs(int start, int target, vector<int> &candidates,
             vector<int> &path, vector<vector<int>> &res) {
      if (target < 0)
        return;
      if (target == 0) {
        res.push_back(path);
        return; 
      }
      for (int i = start; i < candidates.size(); i++) {
        if((target - candidates[i]) < 0)
          break;
        path.push_back(candidates[i]);
        dfs(i, target - candidates[i], candidates, path, res);
        path.pop_back();
      }
    }
};

int main() {
  Solution sol;
  return 0;
}