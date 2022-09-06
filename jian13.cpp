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
using std::vector;
using std::string;
class Solution {
public:
    int movingCount(int m, int n, int k) {
      if (k == 0) {
        return 1;
      }
      vector<vector<bool>> vis(m,vector<bool>(n,false));
      int ans = 1;
      vis[0][0] = true;
      ans += helper(vis, 0, 0, k, m, n);
      return ans;
    }
    int helper(vector<vector<bool>> &vis, int i, int j, int k, int m, int n) {
      int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      int ans = 0;
      for (int d = 0; d < 4; d++) {
        int newi = i + dir[d][0];
        int newj = j + dir[d][1];
        if (newi < 0 || newi >= m || newj < 0 || newj >= n ||vis[newi][newj])
          continue;
        if (check(newi, newj, k)) {
          vis[newi][newj] = true;
          ans++;
          ans += helper(vis, newi, newj, k, m, n);
        }
      }
      return ans;
    }
    bool check(int i, int j, int k) {
      int sum = 0;
      while (i != 0) {
        sum += (i % 10);
        i /= 10;
      }
      while (j != 0) {
        sum += (j % 10);
        j /= 10;
      }
      if (sum <= k)
        return true;
      return false;
    }
};

int main() {
  Solution sol;
  //sol.check(12, 123, 12);
  cout << sol.movingCount(3, 2, 17) << endl;
  cout << sol.movingCount(3, 2, 2) << endl;
  return 0;
}