#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>


using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
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
  using std::priority_queue;
  priority_queue<int> q;
  for (auto k : {12, 5, 3, 21, 7, 8, 6}) {
    q.push(k);
  }
  int n = q.size();
  for (int i = 0; i < n; i++) {
    cout << q.top() << endl;
    q.pop();
  }
  return 0;
}