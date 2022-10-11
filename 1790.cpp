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
using std::vector;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> diff;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;
                diff.push_back(i);
            }
        }
        if(cnt != 0 && cnt != 2)
            return false;
        if(cnt == 0)
            return true;
        else
            return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};

int main() {
  Solution sol;
  cout << sol.areAlmostEqual("kanb", "bank");
  return 0;
}