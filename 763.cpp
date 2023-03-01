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
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::vector;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> ans;
    map<char, int> loc;
    for (int i = 0; i < n; i++) {
      loc[s[i]] = i;
    }
    int p0 = 0, p1  = 0;
    for (int i = 0; i < n; i++) {
      p1 = max(loc[s[i]], p1);
      if (i == p1) {
        ans.push_back(p1 - p0 + 1);
        p0 = p1 + 1;
      }
    }
    return ans;
  }
  vector<int> partitionLabels2(string s) {
    int n = s.size();
    vector<int> ans;
    map<char, int> loc;
    for (int i = 0; i < n; i++) {
      loc[s[i]] = i;
    }
    int p0 = 0, i, p1;
    while (p0 < n) {
      p1 = loc[s[p0]];
      i = p0;
      while (i <= p1) {
        if (loc[s[i]] > p1)
          p1 = loc[s[i]];
        i++;
      }
      ans.push_back(p1 - p0 + 1);
      p0 = p1 + 1;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  string ex1 = {"ababcbacadefegdehijhklij"};
  printV(sol.partitionLabels(ex1), "ans: [9,7,8] -- ");
  return 0;
}