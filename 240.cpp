#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int j = bisearch(matrix[0], target, 0, n - 1);
    if (matrix[0][j] == target)
      return true;
    int i = 1;
    while (i < m && j < n) {
      int l, r;
      if (matrix[i][j] < target) {
        l = j;
        r = n - 1;
      } else {
        l = 0;
        r = j;
      }
      j = bisearch(matrix[i], target, l, r);
      if (matrix[i][j] == target)
        return true;
      else
       i++;
    }
    return false;
  }
  int bisearch(vector<int> &nums, int target, int l, int r) {
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      // num[mid] < target:[mid, r]
      // ==:               [mid, mid]
      // >:                [l, mid-1]
      if (nums[mid] <= target) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 1}};
  sol.searchMatrix(ex1, 0);
  }