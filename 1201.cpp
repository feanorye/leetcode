#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class Solution {
private:
  long long MCM(long long a, long long b) {
    long long mul = a * b;
    while (b > 0) {
      long long tmp = a % b;
      a = b;
      b = tmp;
    }
    return mul / a;
  }

public:
  // assume a<b<c
  int nthUglyNumber(int n, int a, int b, int c) {
    long long m_ab = MCM(a, b);
    long long m_ac = MCM(a, c);
    long long m_bc = MCM(b, c);
    long long m_abc = MCM(m_ab, c);

    long long left = 1, right = (long long)(n * m_abc);
    auto check = [a, b, c, m_ab, m_ac, m_bc, m_abc, n](int mid) {
      long long res =
          (long long)(mid / a) + (long long)(mid / b) + (long long)(mid / c);
      res = res - (long long)(mid / m_ab) - (long long)(mid / m_ac) -
            (long long)(mid / m_bc) + (long long)(mid / m_abc);
      if (res >= n)
        return true;
      return false;
    };
    while (left < right) {
      int mid = left + (right - left) / 2;
      // > n: [l, m-1]
      // ==n: [m]
      // < n: [m+1,r]
      if (check(mid))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};

int main() {
  Solution sol;
  cout << "ans: 6 -- " << sol.nthUglyNumber(4, 2, 3, 4) << endl;
  cout << "ans: 4 -- " << sol.nthUglyNumber(3, 2, 3, 5) << endl;
  return 0;
}