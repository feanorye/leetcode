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
  int bisearch(vector<int> &nums, int target) {
    int len = nums.size();
    int left = 0, right = len - 1;
    while (left < right) {
      int m = left + (right - left) / 2;
      // nums[m] < target: [m+1, right]
      //         ==      : [left, m]
      //          >      : [left, m-1]
      if (nums[m] < target) {
        left = m + 1;
      } else {
        right = m;
      }
    }
    return left;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return {-1, -1};
    int low = bisearch(nums, target);
    if (nums[low] != target)
      return {-1, -1};
    int high = low;
    for (int i = low + 1; i < nums.size(); i++) {
      if (nums[i] != target)
        break;
      high = i;
    }
    return {low, high};
  }
};

int main() {
  Solution sol;
  vector<int> ex5 = {2, 2};
  printV(sol.searchRange(ex5, 3), "ans: [-1,-1]- ");
  vector<int> ex4 = {1};
  printV(sol.searchRange(ex4, 1), "ans: [0, 0]-- ");
  vector<int> ex3 = {5, 7, 7, 8, 8, 10};
  printV(sol.searchRange(ex3, 8), "ans: [3,4]-- ");
  printV(sol.searchRange(ex3, 0), "ans: [-1,-1]-- ");
  vector<int> ex1 = {};
  printV(sol.searchRange(ex1, 0), "ans: [-1,-1]-- ");
  vector<int> ex2 = {1, 2, 3, 3, 4};
  printV(sol.searchRange(ex2, 3), "ans: [2,3]-- ");
  return 0;
}