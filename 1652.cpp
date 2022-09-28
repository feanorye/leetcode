#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include "listnode.h"

using std::abs;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    int n = code.size();
    vector<int> ans(n, 0);
    int l = 0, r = 0;
    if (k == 0)
      return ans;
    int sum = 0;
    if (k > 0) {
      r = l = 1;
      for (int i = 0; i < k; i++) {
        sum += code[r];
        r = (r + 1) % n; // r would be extra 1 larger.
      }
      r--;
    } else {
      r = l = n - 1;
      for (int i = -k; i > 0; i--) {
        sum += code[l];
        l = (l - 1) % n; // l would be extra 1 smaller;
        if (l < 0)
          l += n;
      }
      l++;
    }
    for (int i = 0; i < n; i++) {
      ans[i] = sum;
      r = (r + 1) % n;
      sum += code[r] - code[l];
      l = (l + 1) % n;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {2, 4, 9, 3} ;
  printV(sol.decrypt(ex1, -2));
  return 0;
}