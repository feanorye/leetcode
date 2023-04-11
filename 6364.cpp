#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
  int miceAndCheese2(vector<int> &reward1, vector<int> &reward2, int k) {
    int len = reward1.size(), ans = 0;
    std::priority_queue<pair<int, int>> pq1, pq2;
    auto pq_init = [](std::priority_queue<pair<int, int>> &pq,
                      vector<int> &reward) {
      for (size_t i = 0; i < reward.size(); i++) {
        pq.push(std::make_pair(reward[i], i));
      }
    };
    pq_init(pq1, reward1);
    pq_init(pq2, reward2);
    int cnt = k, cnt2 = len - k;
    vector<int> is_taken(len, 0);
    while (cnt > 0) {
      auto [rw1, idx1] = pq1.top();
      pq1.pop();
      if (cnt2 > 0 && rw1 < reward2[idx1]) {
        cnt2--;
        ans += reward2[idx1];
      } else {
        cnt--;
        ans += rw1;
      }
      is_taken[idx1] = 1;
    }
    while (cnt2 > 0) {
      auto [rw2, idx2] = pq2.top();
      pq2.pop();
      if (is_taken[idx2] == 1)
        continue;
      ans += rw2;
      cnt2--;
    }
    return ans;
  }
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    size_t len = reward1.size();
    vector<int> diff(len, 0);
    int ans = 0;
    for (int i = 0; i < reward1.size(); i++) {
      diff[i] = reward1[i] - reward2[i];
      ans += reward2[i];
    }
    std::sort(diff.begin(), diff.end());
    for (int i = 0; i < k; i++) {
      ans += diff[len - i - 1];
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 1}, {1, 1}};
  printInt("ans: 2 --", sol.miceAndCheese(ex1[0], ex1[1], 2));
  return 0;
}