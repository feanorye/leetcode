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
    int minimizedStringLength(string s) {
        vector<int> mem(26,0);
        for(auto c : s){
            mem[c-'a']++;
        }
        int ans = 0;
        for(int m : mem){
            if(m >0){
                ans++;
            }
        }
        return ans;
    }
};

int main() {
  Solution sol;
  return 0;
}