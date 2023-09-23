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

int main() {
  vector<string> dir(10);
  string s;
  string key;
  int num_line;
  cin >> key;
  cin >> num_line;
  auto parse = [&dir, &key](string &str) -> int {
    int level = 0;
    int len = str.size();
    string cur_path;
    for (int i = 0; i < len; i++) {
      if (str[i] == '-') {
        level++;
      } else {
        cur_path.push_back(str[i]);
      }
    }
    dir[level] = cur_path;
    if (cur_path.find(key) == std::string::npos) {
      return -1;
    }
    return level + 1;
  };
  for (int i = 0; i < num_line; i++) {
    cin >> s;
    int ret = parse(s);
    if (ret > -1) {
      cout << "/";
      for (int i = 0; i < ret; i++) {
        cout << dir[i];
      }
      cout << endl;
    }
  }
  return 0;
}