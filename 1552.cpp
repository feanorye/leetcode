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
  // 检查在最小距离为dis时，能否放置n个
  bool check(vector<int> &pos, int n, int dis) {
    int pre = pos[0];
    int cnt = 1;
    for (size_t i = 1; i < pos.size(); i++) {
      if (pos[i] - pre >= dis) {
        pre = pos[i];
        cnt++;
      }
    }
    return cnt >= n;
  }

public:
  // 最大化最小距离 + 最小化最大距离采用二分
  int maxDistance(vector<int> &position, int n) {
    if (position.size() <= 1) {
      return 0;
    }
    std::sort(position.begin(), position.end());
    int l = 0;
    int r = position.back() - position[0];

    while (l < r) {
      int m = l + (r - l + 1) / 2;
      // if cnt[m] > n: [m, r]
      //           =  : [m]
      //           <  : [l, m)
      if (check(position, n, m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;
  vector<int> ex1{5, 4, 3, 2, 1, 1000000000};
  printInt("ans: 999999999 -- ", sol.maxDistance(ex1, 2));
  return 0;
}