#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
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
using std::vector;

class Solution {
public:
  int maxProfit(vector<int> &inventory, int orders) {
    constexpr long long mod = 10e8 + 7;
    int n = inventory.size();
    std::sort(inventory.begin(), inventory.end());
    long long sum = 0;
    int i = n - 2;
    while (orders > 0) {
      if (i < 0 || inventory[i] < inventory[i + 1]) {
        // t：如果在当前n-i-1大小空间取orders，需要的层数
        // dis: inv[i] 和 inv[i+1]差值
        long long t = 0, dis = 0;
        // condition:[2,2,3] --> could lead to i == -1, so i+1 == 0
        if (i < 0) {
          t = orders / n;
          dis = inventory[0];
        } else {
          t = orders / (n - i - 1);
          dis = inventory[i + 1] - inventory[i];
        }
        if (t >= dis) {
          sum =
              ((inventory[i + 1] * 2 - dis + 1) * dis / 2 * (n - i - 1) + sum) %
              mod;
          orders -= (n - i - 1) * dis;
        } else {
          sum = (sum + (inventory[i + 1] * 2 - t + 1) * t / 2 * (n - i - 1)) %
                mod;
          orders -= (n - i - 1) * t;
          sum = (sum + (inventory[i + 1] - t) * orders) % mod;
          return sum;
        }
      }
      i--;
    }
    return sum;
  }
};

int main() {
  Solution sol;
  vector<int> ex4 = {1000000000};
  printInt("ans: 21 -- ", sol.maxProfit(ex4, 1000000000));
  vector<int> ex3 = {3, 3, 3};
  printInt("ans:17-- ", sol.maxProfit(ex3, 8));
  vector<int> ex2 = {1, 2, 3, 4, 6, 6};
  printInt("ans: 17 --", sol.maxProfit(ex2, 3));
  printInt("ans: 26 --", sol.maxProfit(ex2, 5));
  printInt("ans: 34 --", sol.maxProfit(ex2, 7));
  vector<int> ex1 = {1, 2, 3, 4};
  printInt("ans: 10 -- ", sol.maxProfit(ex1, 3));
  return 0;
}