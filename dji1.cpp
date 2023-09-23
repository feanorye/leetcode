#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

void combine(string &a, string &b, string &c) {
  map<char, int> mp;
  auto buildHash = [&mp](string &s) {
    mp.clear();
    for (auto c : s) {
      mp[c]++;
    }
    return mp.size();
  };
  int ua = buildHash(a);
  int ub = buildHash(b);
  int uc = buildHash(c);
  cout << ua * ub * uc << endl;
  cout << ua * ub + ub * uc + ua * uc << endl;
}
int main() {
  string a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  combine(a, b, c);
  return 0;
}