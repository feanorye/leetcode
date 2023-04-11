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
  int findMinimumTime_self(vector<vector<int>> &tasks) {
    // start, end, duration
    std::priority_queue<tuple<int, int, int>> task_q;
    for (auto t : tasks) {
      task_q.push(std::make_tuple(t[0], t[1], t[2]));
    }
    return 0;
  }
  int findMinimumTime(vector<vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });
    int ans = 0;
    vector<bool> run(2001, false);
    for (auto &t : tasks) {
      int start = t[0], end = t[1], d = t[2];
      for (int i = start; i <= end; ++i)
        d -= (run[i]? 1:0);                // 去掉运行中的时间点
      for (int i = end; d > 0; --i) // 剩余的 d 填充区间后缀
        if (!run[i]) {
          run[i] = true;
          --d;
          ++ans;
        }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{2, 3, 1}, {4, 5, 1}, {1, 5, 2}};
  printInt("ans: 2 -- ", sol.findMinimumTime(ex1));
  return 0;
}