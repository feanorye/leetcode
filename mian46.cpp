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
using std::to_string;
using std::vector;
class Solution {
public:
  int translateNum(int num) {
    string str = to_string(num);
    int n = str.size();
    //[x1,x2,..., x(i-2),x(i-1),x(i),...,x(n)]
    // dp[i] = | dp[i-1] + dp[i-2], if( x(i-1)+x(i) ) [10,25]
    //         | dp[i-1]
    int pre2 = 0, pre1 = 1, cur = 1;
    for (int i = 1; i < n; i++) {
      pre2 = pre1;
      pre1 = cur;
      string mix = str.substr(i - 1, 2);
      if (mix >= "10" && mix <= "25")
        cur = pre2 + pre1;
      else
        cur = pre1;
    }
    return cur;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}