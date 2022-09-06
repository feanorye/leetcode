#include <algorithm>
#include <corecrt.h>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
class Solution {
public:
  int maximumRemovals(string s, string p, vector<int> &removable) {
    size_t ns = s.size(), np = p.size(), nrm = removable.size();

    auto check = [np, ns, nrm, &removable, &s, &p](int k) {
      vector<bool> state(ns, true);
      for (int i = 0; i <= k; i++) {
        state[removable[i]] = false;
      }
      int j = 0;
      for (int i = 0; i < ns; i++) {
        if (p[j] == s[i] && state[i])
          j++;
        if (j == np)
          break;
      }
      if (j != np)
        return false;
      return true;
    };
    int l = 0, r = nrm - 1;
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      if (check(m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    if (check(l))
      return l + 1;
    return 0;// left fail, means NO ELEM COULD REMOVE.
  }
};

int main() {
  Solution sol;
  string exs[2] = {"abcacb", "ab"};
  vector<int> rm1 = {3, 1, 0};
  sol.maximumRemovals(exs[0], exs[1], rm1);
}