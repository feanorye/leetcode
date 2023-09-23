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
  vector<vector<int>> findPrimePairs(int n) {
    vector<vector<int>> ans;
    vector<int> is_prime(n + 1, 1);
    for (int i = 2; i < n; i++) {
      for (int j = i; j < n; j++) {
        if ((i * j) > n) {
          break;
        }
        is_prime[i * j] = 0;
      }
    }
/*     for (int i = 2; i <= n / 2; i++) {
      if (is_prime[i] == 0 && is_prime[n - i] == 0) {
        ans.emplace_back(vector<int>{i, n - i});
      }
    } */
    return ans;
  }
};

int main() {
  Solution sol;
  printl(sol.findPrimePairs(10));
  return 0;
}