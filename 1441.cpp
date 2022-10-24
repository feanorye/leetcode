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
  vector<string> buildArray(vector<int> &target, int n) {
    string str[2] = {"Push", "Pop"};
    vector<string> ans;
    int i = 0;
    for (auto k : target) {
      while (i < k) {
        ans.emplace_back(str[0]);
        ans.emplace_back(str[1]);
        i++;
      }
      ans.emplace_back(str[0]);
      i++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {2, 4};
  printStrA(sol.buildArray(ex1, 5));
  return 0;
}