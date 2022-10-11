#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<int>> col, row, grp;
    col.resize(9, vector<int>(9, 0));
    row.resize(9, vector<int>(9, 0));
    grp.resize(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';
          col[j][num] += 1;
          row[i][num] += 1;
          grp[i / 3 * 3 + j / 3][num] += 1;
          if (col[j][num] > 1 || row[i][num] > 1 ||
              grp[i / 3 * 3 + j / 3][num] > 1)
            return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << sol.isValidSudoku(board);
  cout << "over\n";
  using std::string;
  string ans = "max";
  string trl = "love you";
  ans += (" " + trl);
  
  cout << ans;
}