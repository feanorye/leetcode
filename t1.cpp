#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::lower_bound;
using std::upper_bound;
using std::vector;
void print(vector<vector<int>> &mat) {
  for (auto k1 : mat) {
    for (auto k2 : k1)
      cout << k2 << " ";
    cout << endl;
  }
  cout << endl;
}
auto f(int len) -> int {
  int arr[len];
  std::memset(arr, len, sizeof(arr));
  for (int v : arr) {
    cout << v << " ";
  }
  cout << endl;
  return 1;
}
class ss {
private:
  static int s;
  int normal;
  std::string name;

public:
  ss(std::string n) : normal(11), name(n) {}
  void print() {
    std::cout << name << " ->static: " << s << " normal:" << normal << endl;
    s++;
  }
  void inits() { s = 11; }
};
int main() {
  int k = 15;
  int i = 12;
  k -= i + 3;
  cout << k << endl;
  return 0;
}
