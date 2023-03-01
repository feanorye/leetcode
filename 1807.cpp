#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
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
using std::unordered_map;

class Solution {
public:
  string evaluate2(string s, vector<vector<string>> &knowledge) {
    string ans;
    size_t len = s.size();
    unordered_map<string, string> kv;
    for (auto elem : knowledge) {
      kv[elem[0]] = elem[1];
    }
    string key, val;
    for (int i = 0; i < len; i++) {
      // ans += str_before_brace + key
      // construce key
      if (s[i] == '(') {
        key.erase();
        for (int j = i + 1; j < len; j++) {
          if (s[j] == ')') {
            i = j;
            break;
          } else
            key.push_back(s[j]);
        }
        val = (kv.count(key) > 0) ? kv[key] : string{"?"};
        ans += val;
      } else
        ans.push_back(s[i]);
    }
    return ans;
  }
  string evaluate(string s, vector<vector<string>> &knowledge) {
    string val, ans;
    size_t pos = 0, len = s.size();
    auto check_val = [&knowledge](const string &key) {
      for (auto element : knowledge) {
        if (element[0] == key) {
          return element[1];
        }
      }
      return string{"?"};
    };
    while (pos < len) {
      // ans += str_before_brace + key
      size_t start = s.find('(', pos), end = s.find(')', pos);
      string key = s.substr(start + 1, end - start - 1);
      val = check_val(key);
      ans += s.substr(pos, start - pos);
      ans += val;
      pos = end + 1;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> ex1 = {{"name", "bob"}, {"age", "two"}};
  string str = "(name) is (age) years old(a)";
  string str2 = "(name)is(age)yearsold(a)";
  cout << sol.evaluate2(str2, ex1);
  return 0;
}