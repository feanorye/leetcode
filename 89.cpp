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
  /*
  * 0, 00, 000
  * 1, 01, 001
  *    11, 011
  *    10, 010
  *        110
  *        111
  *        101
  *        100
  */
  vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);

    int head = 1;
    for (int i = 0; i < n; i++) {
      for (int j = res.size() - 1; j >= 0; j--) {
        res.push_back(head + res[j]);
      }
      head <<= 1;
    }
    return res;
  }
};

int main() {
  Solution sol;
  return 0;
}