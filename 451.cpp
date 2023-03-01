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

using std::cout;
using std::endl;
using std::map;
using std::unordered_map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;
using std::priority_queue;

class Solution {
public:
  string frequencySort(string s) {
    string ans;
    unordered_map<char, int> hash;
    for (auto c : s) {
      hash[c]++;
    }
    vector<pair<char,int>> str_vec;
    for (auto &it : hash) {
      str_vec.emplace_back(it);
    }
    std::sort(str_vec.begin(), str_vec.end(),
              [](const pair<char, int> &a, const pair<char, int> &b) {
                return a.second > b.second;
              });
    for (auto v : str_vec) {
      ans.append(string(v.second,v.first));
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}