#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>


int main() {
  using namespace std;
  cout << "x \t x/4 \t (x+4-1)/4\t\n";
  for (int i = 4; i < 10; i++) {
    cout << i << " " << (i / 4) << " " << ((i + 4 - 1) / 4) << endl;
  }
  vector<int> ex = {1, 2, 4, 4, 5};
  auto it = lower_bound(ex.begin(), ex.end(), 3);
  cout << *it << " " << *(it + 1) << endl;
  auto check = [&](int i) { ex.push_back(i); };
  auto disp = [&]() {
    cout << "ex: ";
    for (auto x : ex) {
      cout << x << " ";
    }
    cout << endl;
  };
  check(2);
  disp();
  check(233);
  disp();
  vector<int> ex1 = {2, 4, 1, 12, 5, 8, 34, 23, 51, 14};
  unordered_map<int, int> uhash;
  map<int, int> hash;
  int i = 0;
  for (auto x : ex1) {
    hash[x] = i;
    uhash[x] = i;
    i++;
  }
  cout << "uhash\n";
  for (auto [k, v] : uhash) {
    cout << "key:val-> " << k << ":" << v << endl;
  }
  cout << "hash\n";
  for (auto [k, v] : hash) {
    cout << "key:val-> " << k << ":" << v << endl;
  }
  int m, n;
  if (true)
    m = 1, n = 2;
  cout << "m:n " << m << " " << n << endl;

  return 0;
}