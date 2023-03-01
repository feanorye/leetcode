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
using std::sort;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    int left = intervals[0][0];
    int right = intervals[0][1];

    for (int i = 1; i < n;i++) {
      if (right >= intervals[i][0])
        right = max(intervals[i][1], right);
      else {
        ans.emplace_back(vector<int>{left, right});
        left = intervals[i][0];
        right = intervals[i][1];
      }
    }
    // above code would skip final one.
    ans.emplace_back(vector<int>{left, right});

    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{1, 4}, {1, 5}};
  printl(sol.merge(ex2));
  vector<vector<int>> ex1 = {{1, 2}, {2, 3}, {4, 5}};
  printl(sol.merge(ex1));
  return 0;
}