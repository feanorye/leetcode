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
  // 完成numCourses门课，每门课有前置课程，分析是否能够完成->依赖关系分析
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>());
    vector<int> ingress(numCourses, 0); //记录依赖数量
    for (auto arr : prerequisites) {
      int cur = arr[0], pre = arr[1];
      adj[pre].push_back(cur);
      ingress[cur]++;
    }
    queue<int> start;
    for (int cur = 0; cur < numCourses; cur++) {
      // 此处会将没有依赖的项目，即使要求数组中没有的课，也会加进去
      if (ingress[cur] == 0)
        start.push(cur);
    }
    // BFS
    while ( !start.empty()) {
      int pre = start.front();
      start.pop();
      numCourses--;
      for (int cur : adj[pre]) {
        ingress[cur]--;
        if (ingress[cur] == 0) {
          start.push(cur);
        }
      }
    }
    // todo: 为什么？
    return numCourses == 0;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 0}, {1, 3}, {0, 3}};
  printInt("ans: true -- ", sol.canFinish(5, ex1));
  vector<vector<int>> ex2 = {{0, 1}};
  printInt("ans: true -- ", sol.canFinish(2, ex2));
  return 0;
}