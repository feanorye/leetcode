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
  int preSum[1001];

public:
  Solution() {
    preSum[0] = 0;
    string power;
    for (int i = 1; i < 1001; i++) {
      power = std::to_string(i * i);
      int ret = 0;
      if (dfs(0, 0, i, power.size(), power)) {
        ret += i * i;
      }
      preSum[i] = preSum[i - 1] + ret;
    }
  }
  // given string "1234", enum substring to add
  bool dfs(int pos, int sum, int target, int n, string &str) {
    if (pos == n) {
      return (sum == target);
    }
    int x = 0;
    for (int i = pos; i < n; i++) {
      x = x * 10 + str[i] - '0';
      if (dfs(i + 1, sum + x, target, n, str)) {
        return true;
      }
    }
    return false;
  }
  // 惩罚数：i * i 分割子字符串，相加为i
  // 将所有满足条件的 1 < i < n相加
  // n = 10, i = 10:
  //            1 * 1 = 1 => 1
  //            9 * 9 = 81 => 8 + 1 = 9
  //            10 * 10 = 100 => 10 + 0 = 10
  int punishmentNumber2(int n) {
    // i, i*i
    return preSum[n];
  }
  int punishmentNumber(int n) {
    std::function<bool(int, int)> dfs = [&](int x, int target) {
      if (x <= target)
        return x == target;
      int v = 0, m = 1;
      while (x) {
        v = m * (x % 10) + v, x /= 10, m *= 10;
        if (v > target)
          break;
        if (dfs(x, target - v))
          return true;
      }
      return false;
    };
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (dfs(i * i, i))
        sum += i * i;
    }
    return sum;
  }
};

int main() {
  Solution sol;
  printInt("ans: 182 -- ", sol.punishmentNumber(10));
  return 0;
}