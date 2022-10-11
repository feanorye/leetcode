#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class Solution {
private:
  bool check(vector<int> &day, int upper_day, int num_flower, int k,
             vector<bool> &mark) {
    int n = day.size();
    for (int i = 0; i < n; i++)
      mark[i] = (day[i] <= upper_day);
    int cnt = 0;
    for (int i = 0; i < n;) {
      if (mark[i]) {
        i++;
        int j = 1;
        for (; j < k && i < n; j++, i++) {
          if (!mark[i])
            break;
        }
        if (j == k)
          cnt++;
      } else {
        i++;
      }
    }
    // return cnt;
    return cnt >= num_flower;
  }

public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (m * k > n)
      return -1;
    vector<bool> mark(n, false);
    int l = 1, r = (int)10e9;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (check(bloomDay, mid, m, k, mark))
        r = mid;
      else
        l = mid + 1;
    }
    return check(bloomDay, l, m, k, mark) ? l : -1;
  }
  // need change check()->int
  void test() {
    vector<int> ex1 = {1, 2, 3, 4, 5, 6, 7};
    int n = ex1.size();
    vector<bool> mark(n, false);
    cout << "ans: 0 -- " << check(ex1, 0, 3, 3, mark) << endl;
    cout << "ans: 1 -- " << check(ex1, 3, 3, 3, mark) << endl;
    cout << "ans: 2 -- " << check(ex1, 6, 3, 3, mark) << endl;
  }
};

int main() {
  Solution sol;
  // sol.test();
  vector<int> ex1 = {1, 10, 3, 10, 2};
  cout << "ans: 3 -- " << sol.minDays(ex1, 3, 1) << endl;
  return 0;
}