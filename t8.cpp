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
#include <sstream>

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
using std::stringstream;

class Solution {
public:
  vector<string> test() {
    string str = "zhang hui tao ", elem;
    stringstream s(str);
    vector<string> res;
    while (s >> ( elem)) {
      res.emplace_back(elem);
    }
    return res;
  }
};

int main() {
  Solution sol;
  sol.test();
  map<string, char> hash;
  hash.count("zhang");
  vector<vector<int>> ans;
  ans.emplace_back(vector<int>{1, 2});
  printl(ans);
  return 0;
}