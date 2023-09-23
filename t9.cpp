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
  int m = 0;
  auto check = [&m]() { cout << "now: " << m << endl; };
  for (int i = 0; i < 4; i++) {
    m++;
    check();
  }
  return 0;
} 