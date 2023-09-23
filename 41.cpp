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
  // 给定乱序数组，返回缺失的最小正整数
  int firstMissingPositive(vector<int> &nums) {
    // 原地哈希方法: 把正整数i映射到数组第i-1位置，负数放在任意位置
    int i = 0, n = nums.size();
    while (i < n) {
      // 注意这里：当前元素不在应在位置时才处理，使用Jian03方法
      // 容易导致死循环
      if (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }else {
      i++;
      }
    }
    // 排序完成，从头进行对比
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1)
        return i+1;
    }
    return n-1;
  }
};

int main() {
  Solution sol;
  vector<int> ex1{3, 4, 2, 1, 1, 0};
  printInt("ans: 5 -- ", sol.firstMissingPositive(ex1));
  return 0;
}