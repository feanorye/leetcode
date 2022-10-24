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
  int maxChunksToSorted(vector<int> &arr) {
    int ans = 0;
    // 分别表示chunk的上下限
    stack<int> min_st, max_st;
    // 正在处理的上限
    int current_top = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (current_top < arr[i])
        current_top = arr[i];

      while (!min_st.empty()) {
        if (min_st.top() > arr[i] || max_st.top() > arr[i]) {
          min_st.pop();
          max_st.pop();
        } else {
          break;
        }
      }
      max_st.push(current_top);
      min_st.push(arr[i]);
    }
    ans = min_st.size();
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {5, 2, 6, 3, 7, 4, 8};
  printInt("ans: 2 -- ", sol.maxChunksToSorted(ex2));
  vector<int> ex1 = {8, 7, 9, 6, 10, 11, 13, 12};
  printInt("ans: 4 -- ", sol.maxChunksToSorted(ex1));
  return 0;
}