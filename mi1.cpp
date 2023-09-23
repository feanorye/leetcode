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

using std::cin;
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


int dijkstra(vector<vector<int>> &g, int k) {
  using PII = pair<int, int>;
  int ans = 0;
  // {length, node}
  std::priority_queue<PII, vector<PII>, std::greater<>> pq;
  pq.emplace(0, 1);
  while (!pq.empty()) {
    auto [length, node] = pq.top();
    pq.pop();
    if (length > k) {
      break;
    }
    ans++;
    if (g[node].size() == 0) {
      ans += k - length;
    } else {
      for (int nx_ndoe : g[node]) {
        pq.emplace(length + 1, nx_ndoe);
      }
    }
  }
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> gp(n + 1);
  for (int i = 1; i < n; i++) {
    int node, next_node;
    cin >> node >> next_node;
    gp[node].push_back(next_node);
  }
  cout << dijkstra(gp, k);
  return 0;
}