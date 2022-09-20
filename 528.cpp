#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
using std::random_device;
class Solution {
private:
  std::mt19937 gen;
  std::uniform_int_distribution<int> dis;
  vector<int> pre;

public:
  Solution(vector<int> &w)
      : gen(random_device{}()), dis(1, std::accumulate(w.begin(), w.end(), 0)) {
    int n = w.size();
    pre.resize(n, 0);
    pre[0] = w[0];
    for (int i = 1; i < n; i++) {
      pre[i] = pre[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int t = dis(gen);
    cout <<"find: " <<  t << " ";
    return find(t);
  }
  // find 1st target <= pre[i]
  int find(int t) {
    int left = 0;
    int right = pre.size();
    while (left < right) {
      int m = left + (right - left) / 2;
      // < :[l,m]
      // = :[m]
      // > :[m + 1, r]
      if (t <= pre[m]) {
        right = m;
      } else {
        left = m + 1;
      }
    }
    return left;
  }
};

int main() {
  vector<int> ex1 = {3, 1, 2, 3};
  Solution sol(ex1);
  for (int i = 0; i < 15; i++)
    cout << sol.pickIndex() << endl;
  return 0;
}