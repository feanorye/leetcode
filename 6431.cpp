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
      bool doesValidArrayExist(vector<int>& d) {
        int len = d.size();
        // assume a[0] == 0
        // d[0]: 0 -> same with a[0] 
        //       1 -> diff with a[0]
        int p = 0;
        for (int i = 0; i < len; i++) {
          if (d[i] == 1) {
            p ^= 1;
          }
        }
        return p == 0;

}
};

int main() {
  Solution sol;
  return 0;
}