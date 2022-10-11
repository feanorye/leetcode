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
private:
  bool print(vector<vector<long long>> &left) {
    for (auto e : left) {
      cout << "[";
      for (auto k : e)
        cout << k << ",";
      cout << "\b]\n";
    }
    return false;
  }

public:
  vector<vector<long long>> multiply(vector<vector<long long>> &a,
                                     vector<vector<long long>> &b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
      }
    }
    return c;
  }

  vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
    vector<vector<long long>> ret = {{1, 0}, {0, 1}};
    while (n > 0) {
      if ((n & 1) == 1) {
        ret = multiply(ret, a);
/*         cout << "a: \n";
        print(a);
        cout << "ret: \n";
        print(ret); */
      }
      n >>= 1;
      a = multiply(a, a);
    }
    return ret;
  }

  int climbStairs(int n) {
    vector<vector<long long>> ret = {{1, 1}, {1, 0}};
    vector<vector<long long>> res = matrixPow(ret, n);
    return res[0][0];
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  sol.climbStairs(7);
  return 0;
}