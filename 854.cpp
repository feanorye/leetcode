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
  int kSimilarity(string s1, string s2) {
    result = 0xffff;
    int n = s1.size();
    helper(s1, s2, 0, 0, n);
    return result;
  }

private:
  int result;
  // change s1 --> s2
  void helper(string s1, string s2, int start, int count, int len) {
    if (start + 1 == len) {
      result = min(count, result);
      return;
    }
    if (count > result) {
      return;
    }
    for (int i = start; i < len; i++) {
      if (s1[i] != s2[i]) {
        for (int j = i + 1; j < len; j++) {
          if (s1[j] == s2[i] && s1[j] != s2[j]) {
            swap(s1, i, j);
            helper(s1, s2, i + 1, count + 1, len);
            swap(s1, i, j);
          }
        }
        //不可break, 否则下方result会更新为当前count
        return;
      }
    }
    // all same
    result = count;
  }
  void swap(string &s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
};

int main() {
  Solution sol;
  string ex2[2] = {"bccaba","abacbc"};
  cout << "ans: 3 -- " << sol.kSimilarity(ex2[0], ex2[1]) << endl;
  string ex1[2] = {"abba", "baab"};
  cout << "ans: 2 -- " << sol.kSimilarity(ex1[0], ex1[1]) << endl;
  return 0;
}