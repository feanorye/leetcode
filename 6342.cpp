#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> Rcnt(m, 0), Ccnt(n, 0);
    map<int, pair<int, int>> hash;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        hash[mat[i][j]] = std::make_pair(i, j);
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      auto [x, y] = hash[arr[i]];
      if (++Rcnt[x] >= n || (++Ccnt[y] >= m))
        return i;
    }
    return arr.size();
  }
};

int main() {
  Solution sol;
  return 0;
}