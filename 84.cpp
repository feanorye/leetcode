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
  // 最大柱形面积
  int largestRectangleArea(vector<int> &heights) {
    // 单调栈：每个柱子，找到第一个小于该柱子高度的左右边界
    stack<int> st;
    // st.push(0); //需要哨兵作为最后元素的左边界
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    int len = heights.size();
    int ans = 0;
    // 单调递增的高度，需要最后最低元素让单调栈出栈
    for (int i = 0; i < len; i++) {
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int h = heights[st.top()];
        st.pop();
        // 栈中元素起效宽度：左边比该元素小的元素位置，右边比该元素小的元素位置
        // 如：0,[2,1,5,6,2,3],0  哨兵
        // 1的左边界为0，右边界为0，则宽度为 i - st.top -1
        //                              = 7 - 0 - 1
        //                              = 6
        int w = i - st.top() - 1;
        ans = max(ans, h * w);
      }
      // 递增单调栈：栈顶元素下一个元素则为栈顶元素的左边界
      st.push(i);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{2,2, 3, 2, 0, 3, 1, 4, 1, 2};
  printInt("ans: 8 -- ", sol.largestRectangleArea(ex2));
  vector<int> ex1 = {2, 1, 5, 6, 2, 3};
  printInt("ans: 10 -- ", sol.largestRectangleArea(ex1));
  return 0;
}