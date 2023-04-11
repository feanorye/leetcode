#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
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
  bool is_back(string &str, int st, int ed) {
    while (st < ed) {
      if (str[st] != str[ed])
        return false;
      st++;
      ed--;
    }
    return true;
  }
  bool check(string &a, string &b) {
    int i = 0, j = a.size()-1;
    while (i < j) {
      if (a[i] != b[j])
        break;
      i++;
      j--;
    }
    return is_back(a, i, j) || is_back(b, i, j);
  }
  // 相同下标分开，使之出现一个回文串
  bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
  }
};

int main() {
  Solution sol;
  cout << "ans: true -- "<< sol.checkPalindromeFormation("abdef", "fecab") << endl;
  cout << "ans: true -- "<< sol.checkPalindromeFormation("ulacfd", "jizalu") << endl;
  cout << "ans: false -- "<< sol.checkPalindromeFormation("xbdef", "xecab") << endl;
  cout << "ans: true -- "<< sol.checkPalindromeFormation("a", "b") << endl;
  return 0;
}