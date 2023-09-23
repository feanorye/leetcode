#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
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
  vector<int> primes_;

public:
  Solution() {
    const int mx = 5e6 + 1;
    vector<bool> is_prime(mx, true);
    for (int i = 2; i < mx; i++) {
      if (is_prime[i]) {
        primes_.push_back(i);
      }
      for (int j = i; j <= (mx / i); j++) {
        is_prime[i * j] = false;
      }
    }
    // make all primes[] < mx
    // primes_.push_back(mx);
  }
  // return index of last elem which < n
  int bisearch(int n) {
    int l = 0, r = primes_.size() - 1;
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      // p[m] < n: [m, r]
      //      == : [l, m-1]
      //      >  : [l, m-1]
      if (primes_[m] < n) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
  int countPrimes(int n) {
    int idx = bisearch(n);
    if(primes_[idx] < n)
      return idx + 1;
    return 0;
  }
};

int main() {
  Solution sol;
  printInt("ans: 348513 -- ", sol.countPrimes(5000000));
  printInt("ans: 78497 -- ", sol.countPrimes(999983));
  printInt("ans: 4 -- ", sol.countPrimes(10));
  return 0;
}