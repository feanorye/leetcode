#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
  int maxProduct(vector<int> &nums) {
    int  maxF = 1, minF = 1, ans;
    for (auto item : nums) {
      if (item < 0) {
        std::swap(maxF, minF);
      }
      maxF = max(maxF * item, item);
      minF = min(minF * item, item);
      ans = max(maxF, ans);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {2, -5, -2, -4, 3};
  printInt("ans: 24 -- ", sol.maxProduct(ex3));

  vector<int> ex1 = {1, 2, -3, 4, -2, -1};
  printInt("ans: 48 -- ", sol.maxProduct(ex1));

  vector<int> ex2 = {1, -2, 3};
  printInt("ans: 3 -- ", sol.maxProduct(ex2));
  return 0;
}