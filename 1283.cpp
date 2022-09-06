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
  // find min(ans| num[i]/ans <= threshold)
  // div[left] >= div[m] >=div[right]
  // => find 1st div[i] <= threshold
  int smallestDivisor(vector<int> &nums, int threshold) {
    int left = 1;
    int right = 0;
    for (auto v : nums) {
      right = (right > v) ? right : v;
    }
    while (left < right) {
      int m = left + (right - left) / 2;
      int sum = 0;
      for (auto v : nums) {
        sum += ((v + m - 1) / m);
      }
      // sum <  threshold:[left, m]
      // sum == threshold:[left, m]
      // >:            [m+1, right]
      if (sum <= threshold) {
        right = m;
      } else {
        left = m + 1;
      }
    }
    return left;
  }
};

int main() { Solution sol; }