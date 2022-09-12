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
using std::pair;
using std::string;
using std::vector;
class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                           vector<int> &worker) {
    int ans = 0;
    int len = difficulty.size();
    vector<pair<int, int>> req;
    for (int i = 0; i < len; i++) {
      req.emplace_back(difficulty[i],profit[i]);
    }
    std::sort(req.begin(), req.end());
    std::sort(worker.begin(), worker.end());
    int wl = worker.size();
    int mx = 0, j = 0;
    for (int i = 0; i < wl; i++) {
      while (j < len && req[j].first <= worker[i])
        mx = std::max(mx, req[j++].second);
      ans += mx;
    }
    return ans;
  }
  int maxProfitAssignment2(vector<int> &difficulty, vector<int> &profit,
                           vector<int> &worker) {
    std::sort(worker.begin(), worker.end());
    int len = difficulty.size();
    // requirement store
    vector<pair<int, int>> req;
    for (int i = 0; i < len; i++) {
      req.emplace_back(difficulty[i], profit[i]);
    }
    std::sort(req.begin(), req.end());
    int sum = 0;
    for (auto x : worker) {
      sum += binSearch(req, x);
    }
    return sum;
  }
  // return: index of result
  int binSearch(vector<pair<int, int>> &req, int target) {
    int left = 0;
    int right = req.size(); // target could be greater than size;
    while (left < right) {
      int m = left + (right - left) / 2;
      // > :  [l, m]
      // == : [m]
      // <:   [m+1, r]
      if (req[m].first > target) {
        right = m;
      } else {
        left = m + 1;
      }
    }
    int maxV = 0;
    for (int i = 0; i < left; i++) {
      maxV = std::max(req[i].second, maxV);
    }
    return maxV;
  }
};

int main() {
  Solution sol;
  vector<int> ex11 = {2, 4, 6, 8, 10};
  vector<int> ex12 = {10, 20, 30, 40, 50};
  vector<int> ex13 = {4, 5, 6, 7};
  cout << sol.maxProfitAssignment(ex11, ex12, ex13) << endl;
  vector<int> ex21 = {13, 37, 58};
  vector<int> ex22 = {4, 90, 96};
  vector<int> ex23 = {34, 73, 45};
  cout << sol.maxProfitAssignment(ex21, ex22, ex23) << endl;
  return 0;
}