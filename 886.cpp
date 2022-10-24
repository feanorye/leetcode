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
using std::set;
using std::stack;
using std::string;
using std::vector;

class Solution {
private:
  bool dfs(int node, int new_color, vector<int> &color,
           vector<vector<int>> &g) {
    color[node] = new_color;
    for (auto dis_node : g[node]) {
      if (color[dis_node] == 0 && !dfs(dis_node, 3 - new_color, color, g))
        return false;
      if (color[dis_node] != 0 && color[dis_node] == color[node])
        return false;
    }
    return true;
  }

public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (auto arr : dislikes) {
      g[arr[0]].push_back(arr[1]);
      g[arr[1]].push_back(arr[0]);
    }
    for (int i = 1; i <= n; i++) {
      if (color[i] == 0 && !dfs(i, 1, color, g))
        return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{1, 2}, {1, 3}, {2, 4}};
  printInt("ans: true -- ", sol.possibleBipartition(4, ex2));
  
  vector<vector<int>> ex1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
  printInt("ans: false -- ", sol.possibleBipartition(5, ex1));
  return 0;
}