#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    vector<vector<int>> newImage = image;
    int m = image.size(), n = image[0].size();
    vector<vector<int>> visited(m,vector<int>(n,-1));
    dfs(newImage, sr,sc,color,image[sr][sc], visited);
    return newImage;
  }
  void dfs(vector<vector<int>> &image, int sr, int sc, int color,
           int oldColor, vector<vector<int>> &vis) {
    int m = image.size();
    int n = image[0].size();
    if (sr < 0 || sr >= m || sc < 0 || sc >= n)
      return;
    if (vis[sr][sc] == 1 || image[sr][sc] != oldColor)
      return;
    image[sr][sc] = color;
    vis[sr][sc] = 1;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto e : dir) {
      int newR = sr + e[0];
      int newC = sc + e[1];
      dfs(image, newR, newC, color, oldColor);
    }
    return;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex2 = {{0, 0, 0}, {0, 0, 0}};
  sol.floodFill(ex2, 0, 0, 0);
  vector<vector<int>> ex1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  sol.floodFill(ex1, 1, 1, 2);
  return 0;
}