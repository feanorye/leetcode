#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <sstream>

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
using std::stringstream;

class Solution {
  int _number;
public:
  Solution(int n) : _number(n) { cout << "Create: " << _number << endl; }
  ~Solution() { cout << "destroy: " << _number << endl; }
  void change(int n) {
    _number = n;
  }
};

int main() {
  Solution sol(1);
  Solution sol2(2);
  cout << "Before move\n";
  sol = std::move(sol2);
  cout << "After move\n";
  sol.change(12);
  cout << "After change\n";
  vector<int> ex1 = {2, 4, 6, 8};
  auto is_even = [](int i) { return i % 2 == 0; };
  std::partition(ex1.begin(), ex1.end(), is_even);
  printV(ex1, "mat: ");
  auto pp = std::partition_point(ex1.begin(), ex1.end(), is_even);
  cout << "final: " << *pp << endl;
  
  return 0;
}