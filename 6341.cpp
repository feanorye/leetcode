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
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int c1 = 0, c2 = 0;
        int prev = 0;
        for(auto s : player1){
            if(prev >= 10){
                c1 += 2 * s;
                prev -= 10;
            }else{
                c1 += s;
            }
            if(s == 10){
                prev = 20;
            }
        }
        prev = 0;
        for(auto s : player2){
            if(prev >= 10){
                c2 += 2 * s;
                prev -= 10;
            }else{
                c2 += s;
            }
            if(s == 10){
                prev = 20;
            }
        }
        if(c1 == c2)
            return 0;
        return c1 > c2? 1 : 2;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{10, 2, 2, 3}, {3, 8, 4, 5}};
  printInt("ans: 1 -- ", sol.isWinner(ex1[0], ex1[1]));
  return 0;
}