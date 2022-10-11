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
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> st;
    int n = nums2.size();
    int s = nums1.size();
    map<int, int> hash;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && st.top() < nums2[i]) {
        hash[st.top()] = nums2[i];
        st.pop();
      }
      st.push(nums2[i]);
    }
    vector<int> ans(s, -1);
    for (int i = 0; i < s; i++) {
      if (hash.count(nums1[i]))
        ans[i] = hash[nums1[i]];
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1[2] = {{4, 1, 2}, {1, 3, 4, 2}};
  printV(sol.nextGreaterElement(ex1[0], ex1[1]), "ans:[-1,3,-1] -- ");
  return 0;
}