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
using std::make_pair;
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
using std::swap;

class Solution {
public:
      bool checkValidGrid(vector<vector<int>>& grid) {
        auto n = grid.size();
        map<int,pair<int, int>> hash;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                hash[grid[i][j]] = make_pair(i, j);
            }
        }
        auto total = n * n;
        auto [row1, col1] = hash[0];
        auto check = [](int r1, int c1, int r2, int c2){
            int d1 = abs(r1 - r2);
            int d2 = abs(c1 - c2);
            if(d1 != 2)
                swap(d1, d2);
            if(d1 == 2 && d2 == 1)
                return true;
            return false;
        };
        
        for(size_t i = 1; i < total; i++){
            auto [row2, col2] = hash[i];
            if(!check(row1, col1, row2, col2))
                return false;
            row1 = row2;
            col1 = col2;
        }
        return true;
}
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{24,11,22,17,4},{21,16,5,12,9},{6,23,10,3,18},{15,20,1,8,13},{0,7,14,19,2}};
  printInt("ans: false -- ", sol.checkValidGrid(ex1));
  return 0;
}