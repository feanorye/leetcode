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
  string makeSmallestPalindrome(string s) {
    string ans{s};
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        if (ans[i] < ans[j]) {
          ans[j] = ans[i];
        } else {
          ans[i] = ans[j];
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.makeSmallestPalindrome(string{"atie"}) << endl;
  cout << sol.makeSmallestPalindrome(string{"abcd"}) << endl;
  return 0;
}