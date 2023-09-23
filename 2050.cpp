#include "listnode.h"
#include <algorithm>
#include <functional>
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
  /**
   * @param n: number of courses
   * @param relations: {pre, cur}, 1 <= course <= n
   * @param time: t0, t1, ... , tn
   * @return 返回需要的最少时间
   */
  int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
    // 类似 207 + 模拟题2532
    vector<vector<int>> adj(n + 1);
    vector<int> ingress(n + 1);
    for (auto rel : relations) {
      int pre = rel[0], cur = rel[1];
      adj[pre].push_back(cur);
      ingress[cur]++;
    }
    using PII = pair<int, int>; // {finish_time, course_i}
    std::priority_queue<PII, vector<PII>, std::greater<>> work_queue;
    for (int i = 1; i <= n; i++) {
      if (ingress[i] == 0) {
        work_queue.push(std::make_pair(time[i-1], i));
      }
    }
    int now = 0;
    // workque只会跳过回环的课程
    while (!work_queue.empty()) {
      auto [t, c] = work_queue.top();
      work_queue.pop();
      if (t > now) {
        now = t;
      }
      for (auto nx : adj[c]) {
        ingress[nx]--;
        if (ingress[nx] == 0) {
          work_queue.push(std::make_pair(time[nx-1] + now, nx));
        }
      }
    }
    return now;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1{{1, 3}, {2, 3}};
  vector<int> ex1t{3, 2, 5};
  printInt("ans: 8 -- ", sol.minimumTime(3, ex1, ex1t));
  return 0;
}