#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class Solution {
public:
  // check "LXXR..." -> "XLXR.."
  bool canTransform(string start, string end) {
    int n = start.size();
    for (int i = 0, j = 0; i < n || j < n; i++, j++) {
      while (i < n && start[i] == 'X')
        i++;
      while (j < n && end[j] == 'X')
        j++;
      // when all finish, ex2: i == j
      if (i == n || j == n)
        return i == j;
      if (start[i] != end[j])
        return false;
      if (start[i] == 'L' && i < j)
        return false;
      if (start[i] == 'R' && i > j)
        return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string ex2[2] = {"RXXLRXRXL", "XRLXXRRLX"};
  cout << "ans: true -- " << sol.canTransform(ex2[0], ex2[1]) << endl;

  string ex1[2] = {"RXXLRXRXL", "XRLXXRRLX"};
  cout << "ans: true -- " << sol.canTransform(ex1[0], ex1[1]) << endl;
  return 0;
}