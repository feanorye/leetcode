#include "listnode.h"
#include <algorithm>
#include <cctype>
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
using std::set;

class Solution {
public:
  // a{b,c}{d,e}f{g,h}, k
  vector<string> braceExpansionII(string expression) {
    vector<char> op;
    vector<std::set<string>> operand;

    auto ope = [&op, &operand]() {
      int l = operand.size()-2, r = operand.size() - 1;
      if (op.back() == '+') {
        // todo:
        operand[l].merge(operand[r]);
      } else {
        set<string> tmp;
        for (auto s1 : operand[l])
          for (auto s2 : operand[r]) {
            tmp.insert(s1+s2);
          }
        operand[l] = std::move(tmp);
        operand.pop_back();
      }
    };
    for (int i = 0; i < expression.size(); i++) {
      // a{b,c}{d,e}
      if (expression[i] == '{') {
        if (i > 0 &&
            (expression[i - 1] == '}' || std::isalpha(expression[i - 1]))) {
          op.push_back('*');
        }
        op.push_back('{');
      }
      // {a,b}c, d
      else if (expression[i] == ',') {
        while (op.size() && op.back() == '*') {
          ope();
        }
        op.push_back('+');
      }
      // {{2}{1,2}}
      else if (expression[i] == '}') {
        while (op.size() && op.back() != '{')
          ope();
        op.pop_back();
      } else {
        // {a,b}cd
        if (i > 0 &&
            (expression[i - 1] == '}' || std::isalpha(expression[i - 1])))
          op.push_back('*');
        operand.push_back({string(1, expression[i])});
      }
    }
    while (op.size())
      ope();

    return vector<string>(operand[0].begin(), operand[0].end());
  }
};

int main() {
  Solution sol;
  return 0;
}