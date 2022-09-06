#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
class Solution {
public:
  string reverseWords(string s) {
    int len = s.size();
    string ans;
    int tail = len - 1;
    bool has = false;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        if (has) {
          ans += s.substr(i + 1, tail - i);
          ans += " ";
          has = !has;
        } else {
          continue;
        }
      } else {
        if (!has) {
          tail = i; 
          has = !has;
        }
      }
    }
    if (s[0] != ' ' && has) {
      ans += s.substr(0, tail + 1);
      ans += " ";
    }
    return ans.substr(0,ans.size() -1 );
  }
};

int main() {
  Solution sol;
  string ans;
  string ex1 = " max love amber ";
  ans = sol.reverseWords(ex1);
  cout << "***"<< ans << "***" << endl;
  }