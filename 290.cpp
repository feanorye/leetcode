#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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
using std::stringstream;
using std::vector;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    map<char, string> cs;
    map<string, char> sc;
    stringstream sb(s);
    string elem;
    int i = 0;
    while (sb >> elem) {
      if ((cs.count(pattern[i]) != 0) || (sc.count(elem) != 0)) {
        if ((cs[pattern[i]] != elem) || (sc[elem] != pattern[i]))
          return false;
      } else {
        cs[pattern[i]] = elem;
        sc[elem] = pattern[i];
      }
      i++;
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<string> ex1 = {"abba", "dog cat cat fish"};
  cout << sol.wordPattern(ex1[0], ex1[1]);
  return 0;
}