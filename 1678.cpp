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
  string interpret(string command) {
    string ans;
    for (int i = 0; i < command.size(); i++) {
      if (command[i] == '(')
        continue;
      if (command[i] == ')') {
        if (command[i - 1] == '(')
          ans += 'o';
        else
          continue;
      } else {
        ans += command[i];
      }

    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}