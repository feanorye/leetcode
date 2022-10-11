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

constexpr long long mod = 1e9 + 7;
class Solution {
private:
  //@brief: return index of 1st element >= target,
  //        if not found, result could be 0 or arr.size()-1;
  int bisearch(vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      // <: [m+1,r]
      // ==:[m]
      // >: [l,m]
      if (arr[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }

public:
  int findBestValue(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int avg = (target - sum) / (n - i);
      if (avg < arr[i]) {
        double davg = (double)(target - sum) / (n - i);
        // (davg +(1-f)) * n = target + n(1-f)
        //  davg * n = taget
        // (davg-f) * n = target - f*n
        // so, if: 1-f < f, i.e: 0.5 < f, avg+1 == result
        if ((davg - avg) > 0.5)
          return avg + 1;
        return avg;
      }
      sum += arr[i];
    }
    //all visited
    return arr[n-1];
  }
  // 通过，8ms
  int findBestValue2(vector<int> &arr, int target) {
    std::sort(arr.begin(), arr.end());
    int n = arr.size();
    // preSum[i]: sum of all ele whose index < i
    vector<long long> preSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      preSum[i + 1] = preSum[i] + arr[i];
    }
    int l = 0, r = arr[n - 1];
    while (l < r) {
      int mid = l + (r - l) / 2;
      int ind = bisearch(arr, mid);
      long long sum = preSum[ind];
      sum += (n - ind) * mid;
      // <: [m+1,r]
      // ==:[m]
      // >: [l,m]
      if (sum < target)
        l = mid + 1;
      else
        r = mid;
    }
    int ind1 = bisearch(arr, l - 1);
    long long sum1 = preSum[ind1] + (n - ind1) * (l - 1);
    int ind2 = bisearch(arr, l);
    long long sum2 = preSum[ind2] + (n - ind2) * (l);
    if (abs(sum1 - target) <= abs(sum2 - target))
      return l - 1;

    return l;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {60864, 25176, 27249, 21296, 20204};

  printInt("ans: 11361 -- ", sol.findBestValue(ex3, 56803));
  vector<int> ex2 = {4, 9, 3};
  printInt("ans: 3 -- ", sol.findBestValue(ex2, 10));
  vector<int> ex1 = {2, 3, 5};
  printInt("ans: 5 -- ", sol.findBestValue(ex1, 10));
  return 0;
}