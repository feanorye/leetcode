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
  // 半有序序列：使序列呈现 1在第一位，n在末尾
  int semiOrderedPermutation(vector<int> &nums) {
    int len = nums.size();
    int head = -1, tail = -1;
    for (int i = 0; i < len; i++) {
      if (nums[i] == 1) {
        head = i;
      } else if (nums[i] == len) {
        tail = i;
      }
    }
    if (head == -1 || tail == -1) {
      return -1;
    }
    int ans = head + len - tail - 1;
    if (head > tail) {
      ans--;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}