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
  // 0: new, 1: false, 2: true
  vector<int> visited;
  /**
   * @brief 在选择state每一位代表的数之后，当前选择能否胜利
   * @param state: idx bit = 1 is idx is taken
   * @param sum: 累加和
   */
  bool dfs(int state, int sum, int max_num, int total) {
    if (visited[state] == 1) {
      return false;
    }
    if (visited[state] == 2) {
      return true;
    }
    for (int i = 1; i <= max_num; i++) {
      // 如果i已经使用过
      if ((1 << i) & state) {
        continue;
      }
      // 如果当前累加和 > total
      if (sum + i >= total) {
        // todo: 为什么这里不是visited[state | (1 << i)] = 2;
        visited[state] = 2;
        return true;
      }
      // 如果选择i之后，对方选择失败
      if (!dfs(state | (1 << i), sum + i, max_num, total)) {
        visited[state] = 2;
        return true;
      }
    }
    visited[state] = 1;
    return false;
  }

public:
  Solution() : visited(1 << 20, 0){};
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    /** 记忆化递归
      简单情况：集合{}存在nums[i] > total, 先手获胜，
               否则total - nums[i], 其set - nums[i]
      todo: 设置不同target对应的集合？如target = 5, find set?
    */
    if (maxChoosableInteger >= desiredTotal)
      return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
      return false;
    return dfs(0, 0, maxChoosableInteger, desiredTotal);
  }
};

int main() {
  Solution sol;
  printInt("ans: true -- ", sol.canIWin(5, 50));
  return 0;
}