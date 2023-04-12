#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::partition_point;
using std::prev;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

struct name {
  int id;
  string name;
};
int main() {
  vector<int> ex = {1, 2, 3, 4};
  cout << "prev 4: "
       << *(prev(partition_point(ex.begin(), ex.end(),
                                 [](const int e) { return e <= 4; })));
  name z = {12, "zhang"};
  auto [id, n] = z;
  cout << "id: " << id << " name: " << n << endl;
  return 0;
}