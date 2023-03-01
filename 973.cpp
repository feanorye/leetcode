#include "listnode.h"
#include <algorithm>
#include <cmath>
#include <functional>
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
using std::pow;
using std::priority_queue;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
      return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    });
    return {points.begin(), points.begin() + k};
  }
  vector<vector<int>> kClosest2(vector<vector<int>> &points, int k) {
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq;
    int n = points.size();
    for (int i = 0; i < n; i++) {
      int dis = pow(points[i][0], 2) + pow(points[i][1], 2);
      pq.emplace(dis, i);
    }
    for (int i = 0; i < k; i++) {
      auto [dis, ind] = pq.top();
      pq.pop();
      ans.push_back(points[ind]);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{-2, 2}, {1, 3}};
  printl(sol.kClosest2(ex1, 1));
  return 0;
}