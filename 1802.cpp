#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
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
public:
  int maxValue(int n, int index, int maxSum) {
    int l = 1, r = maxSum;
    auto check = [&n, &index, &maxSum](int mid) {
      long long rsize = n - index - 1;
      long long lsize = index;
      //等差序列
      long long onesize = mid - 1;
      long long sum = mid;
      if (rsize <= onesize) {
        sum += (rsize * (mid * 2 - rsize - 1)) / 2;
      } else {
        sum += (mid * (mid - 1) / 2 + (rsize - mid + 1));
      }
      if (sum > maxSum)
        return false;
      if (lsize <= onesize) {
        sum += (lsize * (mid * 2 - lsize - 1)) / 2;
      } else {
        sum += (mid * (mid - 1) / 2 + (lsize - mid + 1));
      }
      if (sum > maxSum)
        return false;
      return true;
    };
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;
  printInt("ans: 2 --", sol.maxValue(4, 2, 6));
  return 0;
}