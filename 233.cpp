#include "listnode.h"
#include <algorithm>
#include <cmath>
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
public:
  // <= n的数中1出现的次数，也就是同一个数，如11，算作2次
  // 数位dp
  int countDigitOne2(int n) {
    string num = std::to_string(n);
    int m = num.size();
    vector<vector<int>> memo(m, vector<int>(m, -1));
    std::function<int(int, int, bool)> find = [&](int idx, int cnt,
                                                  bool is_limit) -> int {
      if (idx == m) {
        return cnt;
      }
      if (!is_limit && memo[idx][cnt] > -1) {
        return memo[idx][cnt];
      }
      int up = is_limit ? num[idx] - '0' : 9;
      int res = 0; // idx, cnt对应之后的可能1的个数
      for (int i = 0; i <= up; i++) {
        res += find(idx + 1, cnt + (i == 1), is_limit && up == i);
      }
      if (!is_limit) {
        memo[idx][cnt] = res;
      }
      return res;
    };
    return find(0, 0, true);
  }
  // abcdef-> ab_def-> xx1xxx
  // if(xx<"ab"): 1xxx可谓任意数字[0,999]，xx in[0, ab), count = ab*1000
  //    xx="ab":
  //          if c==0: 0
  //          if c==1: xxx [0,def], count = def+1
  //          if c>1:  xxx [0,999], count = 1000
  int countDigitOne(int n) {
    string num = std::to_string(n);
    int size = num.size();
    int ans = 0;
    int ps[size], ss[size];
    if (size == 1) {
      return n >= 1 ? 1 : 0;
    }
    ps[0] = 0;
    ss[0] = std::stoi(num.substr(1));
    for (int i = 1; i < size - 1; i++) {
      ps[i] = std::stoi(num.substr(0, i));
      ss[i] = std::stoi(num.substr(i + 1));
    }
    ps[size - 1] = std::stoi(num.substr(0, size - 1));
    ss[size - 1] = 0;
    for (int i = 0; i < size; i++) {
      char x = num[i];
      int tot = ps[i] * std::pow(10, size - i - 1);
      if (x > '1') {
        tot += std::pow(10, size - i - 1);
      } else if (x == '1') {
        tot += ss[i] + 1;
      }
      ans += tot;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  printInt("ans: 0-- ", sol.countDigitOne(0));
  printInt("ans: 5-- ", sol.countDigitOne(12));
  return 0;
}