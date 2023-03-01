#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Solution {
private:
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
  int lcm(int a, int b) { return a * b / gcd(a, b); }

public:
  int nthMagicalNumber(int n, int a, int b) {
    int ans = 0;
    int MOD = 1e9 + 7;
    auto check = [n, a, b](int mid) {
      int ln = mid - mid / (b);
      if ((ln + mid) < n)
        return false;
      else
        return true;
    };
    int left = n / 2, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      auto col = check(mid);
      // <:[m+1,r]
      // =:[m]
      // >:[l,m]
      if (col)
        right = mid;
      else
        left = mid + 1;
    }
    int ln = left - left / b;
    ln = ln + left;
    if (ln > n) {
      ans = a * left % MOD;
    } else {
      ans = b * left % MOD;
    }
    return ans;
  }

  int nthMagicalNumber2(int n, int a, int b) {
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
    int c = lcm(a, b);
    long MOD = 1e9 + 7;
    long long left = 0, right = (long long)a * n % MOD;
    while (left < right) {
      int m = left + (right - left) / 2;
      int ln = m / a + m / b - m / c;
      if (ln < n) {
        left = m + 1;
      } else {
        right = m;
      }
    }
    return right;
  }
};

int main() {
  Solution sol;
  printInt("ans: 999860007 -- ",
           sol.nthMagicalNumber2(1000000000, 39999, 40000));
  printInt("ans: 8 -- ", sol.nthMagicalNumber2(3, 6, 4));
  printInt("ans: 6 -- ", sol.nthMagicalNumber2(4, 2, 3));
  return 0;
}