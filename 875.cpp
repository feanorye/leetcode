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
  // find min $k to satisfy: eat all piles in $h hours.
  int minEatingSpeed(vector<int> &piles, int h) {
    if (piles.size() == 0)
      return -1;
    long left = 1, right = piles[0];
    for (auto val : piles) {
      right = (right > val) ? right : val;
    }

    while (left < right) {
      long m = left + (right - left) / 2;
      int realT = 0;
      for (auto val : piles) {
        realT += ((val + m - 1) / m);
      }
      // nums[left] >= nums[right]
      //  < : [left, m-1]
      // == : [left, m]
      //  > : [m+1, right]
      if (realT <= h) { // $m > $ans
        right = m;
      } else {
        left = m + 1;
      }
    }
    return left;
  }
};

int main() {
  Solution sol;
  vector<int> ex2 = {30, 11, 23, 4, 20};
  sol.minEatingSpeed(ex2, 5);
  vector<int> ex1 = {3, 4, 5, 3};
  sol.minEatingSpeed(ex1, 6);
}