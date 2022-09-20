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
private:
  const int mod = 1e9 + 7;

public:
  //双指针法
  int waysToSplit(vector<int> &nums) {
    int n = nums.size();
    int total = 0;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++) {
      total += nums[i];
      pre[i] = total;
    }
    int ans = 0;
    // i < n-2 : => max(i + 1) == n-1, make sure j < n -1 
    for (int i = 0, j = 1, k = 1; i < n-2 && total >= 3 * pre[i]; i++) {
      j = max(j, i+1);
      while (j < n-1 && pre[j] - pre[i] < pre[i])
        j++;
      while (k < n-1 && pre[k] - pre[i] <= total - pre[k])
        k++;
      ans = (ans + k - j) % (int)(1e9 + 7);
    }
    return ans % mod;
  }
};

int main() {
  Solution sol;
  //(0,0,0) 错误，原因逻辑失效
  vector<int> ex1 = {0,0,0};
  cout << sol.waysToSplit(ex1) << endl;
  vector<int> ex2 = {1, 1, 1};
  cout << sol.waysToSplit(ex2) << endl;
  vector<int> ex3 = {1, 2, 2, 2, 5, 0};
  cout << sol.waysToSplit(ex3) << endl;
  return 0;
}