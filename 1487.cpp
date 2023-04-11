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

class Solution {
public:
  vector<string> getFolderNames(vector<string> &names) {
    vector<string> ans;
    std::unordered_map<string, int> hash;
    for (auto name : names) {
      if (!hash.count(name)) {
        ans.push_back(name);
        hash[name]= 1;
      } else {
        int k = hash[name];
        while (hash.count(name + "(" + std::to_string(k) + ")"))
          k++;
        hash[name] = k + 1;
        name = name + "(" + std::to_string(k) + ")";
        hash[name] = 1;
        ans.push_back(name);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<string> ex1 = {"gta", "gta(1)", "gta", "avalon", "gta", "gta(2)"};
  printStrA(sol.getFolderNames(ex1));
  return 0;
}