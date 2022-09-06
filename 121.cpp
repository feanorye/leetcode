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
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int hist[2];
    for (auto &x : hist) {
      x = 0;
    }
    bool downside = true;
    int pre = prices[0];
    int view = prices[0];
    for (auto x : prices) {
      if (downside && x > pre) {
        downside = !downside; // inverse direction
        if (view > pre)
          view = pre;
      } else if (!downside && x < pre) {
        downside = !downside; // inverse direction
        int profit = pre - view;
        if (profit > hist[1]) {
          hist[0] = view;
          hist[1] = profit;
        }
      }
      pre = x;
    }
    int profit = *(prices.end() -1)- view;
    if (profit > hist[1])
      return profit;
    return hist[1];
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1, 2, 3, 2, 5, 6};
  cout << (sol.maxProfit(ex1)) << endl;
}