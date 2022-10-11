#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include "listnode.h"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
using std::map;
class Solution {
  vector<int> left;

public:
  bool exist() {
    vector<int> l = {1, 2, 3, 4};
    left = std::move(l);
    return true;
  }
  bool print() {
    cout << "[";
    for (auto k : left)
      cout << k << ",";
    cout << "\b]\n";
    return false;
  }
};

int main() {
  Solution sol;
  sol.exist();
  sol.print();
  int n = 10;
  while (n--)
    cout << "n & 1 = " << (n & 1) << endl;
  string a = "23";
  cout << "23 < 24 = " << (a < "24") << endl;
  string test = "1234 www.leetcode.com";
  vector<string> arr;
  arr.emplace_back(test.substr(0, 4));
  arr.emplace_back(test.substr(5));
  printStrA(arr);
  int it = 0;
  int i = 0;
  while (true) {
    it = test.find('.',it+1);
    cout << it << "test: " << test.substr(it+1) << endl;
    if (i++ > 5)
      break;
  }
  map<int, vector<int>> mem;
  mem[12].emplace_back(123);
  cout << mem[12][0] << endl;
  return 0;
}