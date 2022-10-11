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
using std::sort;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 1,j = n-1;
    for (; i > 0; i--) {
      if (nums[i - 1] < nums[i])
        break;
    }
    for (; j >=i; j--) {
      if (nums[i - 1] < nums[j]) {
        int tmp = nums[i-1];
        nums[i - 1] = nums[j];
        nums[j] = tmp;
        break;
      }
    }
    std::sort(nums.begin() + i, nums.end());
    //printV(nums,"ans: 15634 -- ");
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 5, 4, 6, 3};
  sol.nextPermutation(ex1);
  return 0;
}