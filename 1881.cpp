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
  string maxValue(string &&n, int x) {
    int l = n.size();

    for (int i = 0; i < l; ++i) {
      if (n[i] - '0' < x) {
        n.insert(i, 1, '0' + x);
        return n;
      }
    }
    n.push_back('0' + x);
    return n;
  }
};

int main() {
  Solution sol;
  cout << "ans: 690 -- " << sol.maxValue("69", 0) << endl;
  cout << "ans: 7629 -- " << sol.maxValue("729", 6) << endl;
  return 0;
}