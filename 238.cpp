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
  // simple edition of following func
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++) {
      ans[i] *= prefix;
      ans[n - i - 1] *= suffix;
      prefix *= nums[i];
      suffix *= nums[n - i - 1];
    }
    return ans;
  }
  // @breif: return vector, whose element is multiply of all
  //         other element.
  // @algo:  ans[i] = all_mul{j < i} * all_mul{j>i}
  vector<int> productExceptSelf3(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    // construct Left multiply of nums[i]
    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int j = n - 1; j >= 0; j--) {
      ans[j] = ans[j] * right;
      right *= nums[j];
    }
    return ans;
  }
  //不能使用除法
  vector<int> productExceptSelf_wrong(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    long long mul = 1;
    int has_z = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        has_z++;
        continue;
      }
      mul = mul * nums[i];
    }
    if (has_z == 1) {
      for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
          ans[i] = mul;
          return ans;
        }
      }
    }
    if (has_z < 1) {
      for (int i = 0; i < n; i++) {
        ans[i] = mul / nums[i];
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, -1, 0};
  printV(sol.productExceptSelf(ex1), "ans: [0,0,-1]");
  return 0;
}