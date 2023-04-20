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
#include <unordered_set>
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
  // 长度为n的数组，p位置为1，其他位置为0
  // banned中记录的位置不可更改，每次选取大小为k的子数组，将其反转（前后颠倒）
  // 求每个位置变为1的最小次数
  vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
    // 位置i反转后的位置j为L+R-i
    // 子数组向右移动1,则j = j+2,向左移动则j = j - 2
    // 故当前位置i的可覆盖范围是[i-k+1, i+k-1]
    // 当i靠近左边界，L=0, R=k-1,则可覆盖范围下界变为(k-i-1)
    // 当i靠近右边界，L=n-k,R=n-1,则范围上界变为(2*n-k-i-1)
    // 故范围边界为 max(i-k+1, k-i-1), min(i+k-1, 2*n-k-i-1)
    vector<int> ans(n, -1);
    vector<int> cur{p}, nxt;
    // set方便插入和删除，注意到i对应的范围内，所有可到达的数为等差数列，故奇偶性和边界一致
    // 则我们将数据分为奇数序号和偶数序号，分别进行处理
    std::set<int> s[2]; 
    std::unordered_set<int> ban{banned.begin(), banned.end()};
    for (int i = 0; i < n; i++) {
      if (i != p && !ban.count(i)) {
        s[i % 2].insert(i);
      }
    }
    // 防止越界
    s[0].insert(n);
    s[1].insert(n);
    ans[p] = 0;
    int steps = 1;
    while (!cur.empty()) {
      for (int i : cur) {
        int mn = max(k - i - 1, i - k + 1);
        int mx = min(2 * n - k - i - 1, i + k - 1);
        // 和 mn 一个奇偶性
        auto &t = s[mn % 2];
        for (auto it = t.lower_bound(mn); *it <= mx; it = t.erase(it)) {
          ans[*it] = steps;
          nxt.push_back(*it);
        }
      }
      steps++;
      cur = std::move(nxt);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2;
  printV(sol.minReverseOperations(4, 2, ex2, 2), "ans: [2,1,0,1] -- ");
  vector<int> ex1 = {1, 2};
  printV(sol.minReverseOperations(4, 0, ex1, 4), "ans: [0,-1,-1,1] -- ");
  return 0;
}