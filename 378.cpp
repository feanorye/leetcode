#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
class Solution {
private:
  // | mat(i) < mid | >= k
  bool check(vector<vector<int>> &mat, int k, int mid, int n) {
    int num = 0;
    for (int i = n - 1, j = 0; i >= 0 && j < n;) {
      if (mat[i][j] <= mid) {
        num += i + 1;
        j++;
      } else {
        i--;
      }
    }
    return num >= k;
  }

public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    int mid = 0;
    while (left < right) {
      mid = left + ((right - left) >> 1);
      // > k: [l, m]
      // =:   [m]
      // <:   [m+1, r]
      if (check(matrix, k, mid, n))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};

int main() {
  Solution sol;
  vector<int> ex1;
  return 0;
}