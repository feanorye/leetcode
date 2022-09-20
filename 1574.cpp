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
  // return index of arr[1st] >= x
  int bfind(vector<int> &arr, int x, int left, int right) {
    while (left < right) {
      // m = left when only [left, right]
      int m = left + (right - left) / 2;
      // > : [left, m]
      // = : [left, m]
      // < : [m+1, right]
      if (arr[m] >= x) {
        right = m;
      } else {
        left = m + 1;
      }
    }
    return left;
  }
  /*    原本：用二分查找直接找数，结果发现还不如顺序查找
      // find arr[] >= arr[lmark]
      int rindex = bfind(arr, arr[lmark], rmark + 1, n);
      // find arr[] > arr[rmark]
      int lindex = bfind(arr, arr[rmark] + 1, 0, lmark);
      int dr = 0, dl = 0;
      if (arr[rindex] < arr[lmark]) {
        dr = rindex - lmark;
      } else {
        dr = rindex - lmark - 1;
      }
      if (arr[lindex] <= arr[rmark]) {
        dr = rmark;
      } else {
        dr = rmark - lindex;
      } */

public:
  void test() {
    vector<int> arr = {2, 2, 2};
    cout << "test: " << bfind(arr, 1, 0, 2) << endl;
  }
  int findLengthOfShortestSubarray(vector<int> &arr) {
    int lmark = -1, rmark = -1;
    int n = arr.size();
    for (int i = 0; i + 1 < n; i++) {
      if (arr[i] > arr[i + 1]) {
        // lmark: ascending end
        // rmark: ascending begining
        if (lmark == -1)
          lmark = i;
        rmark = i + 1;
      }
    }
    // all increase
    if (lmark == -1)
      return 0;

    //[2,2,2,1,1,1]: 只切割一边
    //{2, 2, 2, 5, 4, 3, 1, 3, 4}: 拼接两边，[5,4,3,1]
    //{2,2,2,|5,[4],1|,2,3,4,4,9}
    int res = (lmark + 1 > n - rmark) ? (n - rmark) : (lmark + 1);
    res += rmark - lmark - 1;
    int i = 0, j = rmark;
    for (; i <= lmark && j < n;) {
      if (arr[i] <= arr[j]) {
        // i++会造成删除区域减小
        res = min(j - i - 1, res);
        i++;
      } else {
        // j++增大删除区域
        j++;
      }
    }

    return res;
  }
};

int main() {
  Solution sol;
  sol.test();
  vector<int> ex6 = {6, 3, 10, 11, 15, 20, 13, 3, 18, 12};
  cout << "ans: 8 --" << sol.findLengthOfShortestSubarray(ex6) << endl;
  vector<int> ex3 = {2, 2, 2, 1, 1, 1};
  cout << "ans: 3 --" << sol.findLengthOfShortestSubarray(ex3) << endl;
  vector<int> ex2 = {1, 2, 3, 10, 4, 2, 3, 5};
  cout << "ans: 3 --" << sol.findLengthOfShortestSubarray(ex2) << endl;
  // test all downside
  vector<int> ex1 = {5, 4, 3, 2, 1};
  cout << "ans: 4 --" << sol.findLengthOfShortestSubarray(ex1) << endl;
  // test >3 downside: [2,2,2,3,4]
  vector<int> ex4 = {2, 2, 2, 5, 4, 1, 2, 3, 4, 4, 9};
  cout << "ans: 3 --" << sol.findLengthOfShortestSubarray(ex4) << endl;
  // test only 1 downside
  vector<int> ex5 = {2, 3, 4, 3, 4, 5};
  cout << "ans: 1 --" << sol.findLengthOfShortestSubarray(ex5) << endl;
  return 0;
}