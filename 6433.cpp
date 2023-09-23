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
  int dfs(vector<vector<int>> &grid, vector<vector<int>> &deep, int r, int c) {
    int dir[3] = {-1, 0, 1};
    int m = grid.size(), n = grid[0].size();
    int nc = c + 1;
    if (nc >= n) {
      deep[r][c] = 0;
      return 0;
    }
    int ret = -1;
    for (auto d : dir) {
      int nr = r + d;
      if (nr < 0 || nr >= m || grid[nr][nc] <= grid[r][c])
        continue;
      if (deep[nr][nc] > -1) {
        ret = max(ret, deep[nr][nc]);
      } else {
        ret = max(dfs(grid, deep, nr, nc), ret);
      }
    }
    deep[r][c] = ret + 1;
    return ret + 1;
  }
  int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> deep(m, vector<int>(n, -1));
    int ans = dfs(grid, deep, 0, 0);
    // 第一列中任意位置
    for (int i = 1; i < m; i++) {
      ans = max(dfs(grid,deep, i, 0), ans);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {
      {1000000, 92910, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028,
       1029,    1030,  1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038,
       1039,    1040,  1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048,
       1049,    1050,  1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058,
       1059,    1060,  1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068},
      {1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078,
       1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088,
       1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098,
       1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108,
       1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118}};
  printInt("ans: 49 -- ", sol.maxMoves(ex2));
  vector<vector<int>> ex1{
      {2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
  printInt("ans: 3 -- ", sol.maxMoves(ex1));
  return 0;
}