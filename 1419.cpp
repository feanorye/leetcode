#include "listnode.h"
#include <algorithm>
#include <cstring>
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
  // 一个答案必须是一块空间组合，故应该使用双指针
  int minNumberOfFrogs(string croakOfFrogs) {
    int len = croakOfFrogs.size();
    int mem[5];
    std::memset(mem, 0, 5 * sizeof(int));
    string s{"croak"};

    auto find_c = [&s](char c) -> int {
      for (int i = 0; i < 5; i++) {
        if (s[i] == c)
          return i;
      }
      return -1;
    };
    
    int ans = 0, runing = 0;
    for (int i = 0; i < len; i++) {
      if (croakOfFrogs[i] == 'c') {
        mem[0]++;
        runing++;
        continue;
      }
      int j = find_c(croakOfFrogs[i]);
      if (j == -1 || mem[j - 1] <= mem[j])
        return -1;
      mem[j]++;
      if (j == 4) {
        ans = max(runing, ans);
        runing--;
      }
    }
    return runing == 0?ans:-1;
  }
};

int main() {
  Solution sol;
  printInt("ans: 2 -- ", sol.minNumberOfFrogs(string{"ccrrooaakk"}));
  printInt("ans: 2 -- ", sol.minNumberOfFrogs(string{"crcoakroak"}));
  printInt("ans: 1 -- ", sol.minNumberOfFrogs(string{"croakcroak"}));
  return 0;
}