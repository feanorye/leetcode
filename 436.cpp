#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>


using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::string;
using std::vector;
using std::pair;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      int len = intervals.size();
      vector<int> ans(len, -1);
      vector<pair<int,int>> startInt;
      vector<pair<int,int>> endInt;
      for (int i = 0; i < len; i++ ) {
        startInt.emplace_back(intervals[i][0],i);
        endInt.emplace_back(intervals[i][1],i);
      }
      std::sort(startInt.begin(), startInt.end());
      std::sort(endInt.begin(), endInt.end());
      for (int i = 0, j = 0; i < len && j < len;i++) {
        while(j < len && startInt[j].first < endInt[i].first)
          j++;
        if (j < len)
          ans[endInt[i].second] = startInt[j].second;
      }
      return ans;
    }
};
int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{1, 2}};
  sol.findRightInterval(ex1);
  return 0;
}