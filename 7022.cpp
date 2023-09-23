#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdint.h>
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
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
  // final <=
  int biSearch_low(vector<int> &vec, int target) {
    int l = 0, r = vec.size() - 1;
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      // vec[m] < target: [m, r]
      //        =         [m]
      //        >         [l, m-1]
      if (vec[m] <= target) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return vec[l];
  }
  // first >=
  int biSearch_high(vector<int> &vec, int target) {
    int l = 0, r = vec.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      // vec[m] < target: [m+1, r]
      //        =         [m]
      //        >         [l, m]
      if (vec[m] < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return vec[l];
  }
  void remove_vec(vector<int> &vec, int target) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
      if (*it == target) {
        vec.erase(it);
        return;
      }
    }
  }

public:
  int minAbsoluteDifference2(vector<int> &nums, int x) {
    int len = nums.size();
    vector<int> vec;
    for (int i = x; i < len; i++) {
      vec.push_back(nums[i]);
    }
    std::sort(vec.begin(), vec.end());

    int ub = len - x;
    int ans = INT32_MAX;
    for (int i = 0; i < ub; i++) {
      auto it1 = biSearch_high(vec, nums[i]);
      auto it2 = biSearch_low(vec, nums[i]);
      ans = min(ans, abs(it1 - nums[i]));
      ans = min(ans, abs(it2 - nums[i]));
      remove_vec(vec, nums[i + x]);
    }
    return ans;
  }
  int minAbsoluteDifference(vector<int> &nums, int x) {
    int len = nums.size();
    multiset<int> st;
    for (int i = x; i < len; i++) {
      st.insert(nums[i]);
    }
    int ub = len - x;
    int ans = INT32_MAX;
    for (int i = 0; i < ub; i++) {
      auto it1 = st.lower_bound(nums[i]);
      ans = min(ans, abs(*it1 - nums[i]));
      if (it1 != st.begin()) {
        it1 = std::prev(it1);
        ans = min(ans, abs(*it1 - nums[i]));
      }
      it1 = st.lower_bound(nums[i + x]);
      st.erase(it1);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex5{9, 15, 15};
  printInt("ans: 0 -- ", sol.minAbsoluteDifference(ex5, 1));
  vector<int> ex4{9, 25, 15};
  printInt("ans: 6 -- ", sol.minAbsoluteDifference(ex4, 2));
  vector<int> ex3{71, 4};
  printInt("ans: 67-- ", sol.minAbsoluteDifference(ex3, 1));
  vector<int> ex2{5, 3, 2, 10, 15};
  printInt("ans: 1 -- ", sol.minAbsoluteDifference(ex2, 1));
  vector<int> ex1{4, 3, 2, 4};
  printInt("ans: 0 -- ", sol.minAbsoluteDifference(ex1, 2));
  return 0;
}