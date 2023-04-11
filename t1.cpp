#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
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
int main() {
  using namespace std;
  vector<int> arr = {2, 12, 4, 5};
  sort(arr.begin(), arr.end(), std::greater<int>());
  auto git = upper_bound(arr.begin(), arr.end(), 4);
  auto git2 = upper_bound(arr.begin(), arr.end(), 12);
  auto git3 = lower_bound(arr.begin(), arr.end(), 12);
  auto git4 = lower_bound(arr.begin(), arr.end(), 2);
  vector<int> dis(4, 100);
  dis[0] = std::distance(git, arr.begin());
  dis[1] = std::distance(git2, arr.begin());
  dis[2] = std::distance(git3, arr.begin());
  dis[3] = std::distance(git4, arr.begin());
  for (auto d : dis) {
    cout << d << endl;
	}
  return 0;
}
