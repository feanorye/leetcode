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
  // 返回可被3,5,7整除的所有数之和
  int sumOfMultiples(int n) {
    auto g = [n](int m) -> int {
      int cnt = static_cast<int>(n / m);
      return cnt * m * (1 + cnt) /2;
    };
    return g(3) + g(5) + g(7) - g(15) - g(21) - g(35) + g(105);
  }
};

int main() {
  Solution sol;
  return 0;
}