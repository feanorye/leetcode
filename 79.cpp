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
public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word.size() == 0)
      return true;
    int m = board.size();
    if (m == 0)
      return false;
    int n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    //类似dijkstra
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          vis[i][j] = true;
          if (check(board, word, 1, i, j, vis, m, n))
            return true;
          vis[i][j] = false;
        }
      }
    }
    return false;
  }
  bool check(vector<vector<char>> &board, string word, int index, int i, int j,
             vector<vector<bool>> &vis, int m, int n) {
    if (i >= m || j >= n)
      return false;
    if (index >= word.size())
      return true;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int d = 0; d < 4; d++) {
      int newi = i + dir[d][0];
      int newj = j + dir[d][1];
      if (newi < 0 || newi >= m || newj < 0 || newj >= n || vis[newi][newj])
        continue;
      vis[newi][newj] = true;
      if (board[newi][newj] == word[index] &&
          check(board, word, index + 1, newi, newj, vis, m, n))
        return true;
      vis[newi][newj] = false;
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  sol.exist(ex1, "SEE");
  return 0;
}