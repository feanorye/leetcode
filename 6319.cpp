#include "listnode.h"
#include <algorithm>
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
    vector<int> evenOddBit(int n) {
      // [even, odd]
      int ans[2] = {0, 0};
      int idx = 0;
        while(n != 0){
          int x = 1 & n;
            if( (1 & n) == 1)
              ans[idx]++;
            idx %= 2;
          n = (n >> 1);
        }
        return {ans[0], ans[1]};
    }
};

int main() {
  Solution sol;
  printV(sol.evenOddBit(2), "ans:  0, 1 -- ");
  printV(sol.evenOddBit(17), "ans: 2, 0 -- ");
  return 0;
}