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
using std::stringstream;
using std::vector;

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> ans;
    while (i < n1 || j < n2) {
      if (i == n1) {
        ans.emplace_back(vector<int>{nums2[j][0], nums2[j][1]});
        j++;
        continue;;
      }
      if (j == n2) {
        ans.emplace_back(vector<int>{nums1[i][0], nums1[i][1]});
        i++;
        continue;;
      }
      if (nums1[i][0] == nums2[j][0]) {
        ans.emplace_back(vector<int>{nums1[i][0], nums1[i][1] + nums2[j][1]});
        i++;
        j++;
      } else if (nums1[i][0] < nums2[j][0]) {
        ans.emplace_back(vector<int>{nums1[i][0], nums1[i][1]});
        i++;
      } else {
        ans.emplace_back(vector<int>{nums2[j][0], nums2[j][1]});
        j++;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{148, 597}, {165, 623}, {306, 359}, {349, 566},
                             {403, 646}, {420, 381}, {566, 543}, {730, 209},
                             {757, 875}, {788, 208}, {932, 695}};
  vector<vector<int>> ex2 = {
      {74, 669},  {87, 399},  {89, 165},  {99, 749},  {122, 401}, {138, 16},
      {144, 714}, {148, 206}, {177, 948}, {211, 653}, {285, 775}, {309, 289},
      {349, 396}, {386, 831}, {403, 318}, {405, 119}, {420, 153}, {468, 433},
      {504, 101}, {566, 128}, {603, 688}, {618, 628}, {622, 586}, {641, 46},
      {653, 922}, {672, 772}, {691, 823}, {693, 900}, {756, 878}, {757, 952},
      {770, 795}, {806, 118}, {813, 88},  {919, 501}, {935, 253}, {982, 385}};
  printl(sol.mergeArrays(ex1, ex2));
  return 0;
}