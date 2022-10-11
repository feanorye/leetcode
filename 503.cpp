#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
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
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> arr(n * 2, 0);
    std::copy(nums.begin(), nums.end(), arr.begin());
    std::copy(nums.begin(), nums.end(), arr.begin() + n);
    if (arr.size() != 2 * n) {
      std::cerr << "arr size wrong due to copy nums\n";
      exit(-1);
    }
    for (int i = 2 * n - 1; i >= n; i--) {
      while (!st.empty() && st.top() < arr[i]) {
        st.pop();
      }
      st.push(arr[i]);
    }
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[i] >= st.top()) {
        st.pop();
      }
      ans[i] = (st.empty()) ? -1 : st.top();
      st.push(arr[i]);
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1[2] = {{4, 1, 2}, {1, 3, 4, 2}};
  printV(sol.nextGreaterElements(ex1[1]), "ans:[3,4,-1,3] -- ");
  return 0;
}