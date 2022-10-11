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
#include <wchar.h>

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

class TimeMap {
private:
  map<string, vector<pair<int, string>>> mems;
  /* @_brief: search last element <= target_time
   *
   */
  string bisearch(vector<pair<int, string>> &mem, int target) {
    int n = mem.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      // <:[m,r]
      // ==:[m]
      // >:[l,m-1]
      if (mem[mid].first <= target) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if(mem[l].first > target)
      return {};
    return mem[l].second;
  }

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mems[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp) {
    if (mems.count(key) == 0)
      return {};
    return bisearch(mems[key], timestamp);
  }
};

int main() {
  TimeMap *obj = new TimeMap();
  obj->set("love", "high", 10);
  obj->set("love", "low", 20);
  string param_2 = obj->get("love", 5);
  cout << "ans: '' -- " << param_2 << endl;
  return 0;
}