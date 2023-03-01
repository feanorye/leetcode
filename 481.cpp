#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
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
public:
  int magicalString(int n) {
    static vector<int> res{1, 2, 2};
    static vector<int> prefix{1, 1, 1};
    for (int j = 3, i = 2; j < n; i++) {
      int size = res[i];
      int num = 3 - res[j - 1];
      while (size > 0 && j < n) {
        if (j >= res.size()) {
          res.push_back(num);
          prefix.push_back(prefix.back() + int(num == 1));
        }
        size--;
        j++;
      }
    }
    return prefix[n - 1];
  }
};

int main() {
  Solution sol;
  printInt("ans: 3 -- ", sol.magicalString(6));
  printInt("ans: 4 -- ", sol.magicalString(8));
  return 0;
}