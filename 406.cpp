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
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    int n = people.size();
    vector<vector<int>> ans(n, vector<int>(2, -1));
    std::sort(people.begin(), people.end(),
              [](const vector<int> &lhs, const vector<int> &rhs) {
                if (lhs[0] != rhs[0]) {
                  return lhs[0] < rhs[0];
                } else {
                  return lhs[1] < rhs[1];
                }
              });
    for (auto &v : people) {
      int h = v[0], k = v[1];
      for (int i = 0, k0 = 0; i < n; i++) {
        if (k0 == k && ans[i][0] == -1) {
          ans[i][0] = h;
          ans[i][1] = k;
          break;
        }
        if (ans[i][0] == -1 || ans[i][0] >= h) {
          k0++;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1{{5, 2},{4, 4}, {5, 0}, {6, 1}, {7, 1}, {7, 0}};
  printl(sol.reconstructQueue(ex1));
  return 0;
}