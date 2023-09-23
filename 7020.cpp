#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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
  int countSymmetricIntegers(int low, int high) {
    // {121 112}
    // 偶数位数字，前n位之和= 后n位之和
    auto cnt = [](int n) -> int {
      vector<int> ans{0};
      // 10, 11, 5
      while ((n / 10) != 0) {
        ans.push_back(n % 10 + ans.back());
        n /= 10;
      }
      ans.push_back(n + ans.back());
      int s = ans.size();
      if (s % 2 == 0) {
        return std::pow(10, s-1);
      }
      if (ans[s - 1] - ans[s / 2] == ans[s / 2]) {
        return 1;
      }
      return 0;
    };
    int ans = 0;
    for (int i = low; i <= high;) {
      int next = cnt(i);
      if (next > i) {
        i = next;
        continue;
      }
      ans += next;
      i++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  printInt("ans: 9 -- ", sol.countSymmetricIntegers(1, 100));
  return 0;
}