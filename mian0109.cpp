#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>


using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::vector;
using std::queue;
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
      return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;

    }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}