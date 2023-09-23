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
void quickSort(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int tmp = nums[right];
  int l = left, r = right;
  // r只想> nums[right]的最左侧位置
  // l-1则是<= nums[right]的最右侧位置
  while (l < r) {
    if (nums[l] > tmp) {
      std::swap(nums[l], nums[--r]);
      // 交换之后继续比较
    } else {
      l++;
    }
  }
  std::swap(nums[right], nums[l]);
  quickSort(nums, left, l - 1);
  quickSort(nums, l + 1, right);
}

int main() {
  vector<int> ex1{12, 5, 7, 1, 33, 9};
  quickSort(ex1, 0, ex1.size() - 1);
  printV(ex1, "ans: ");
  return 0;
}