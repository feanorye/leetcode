#include "listnode.h"
#include <algorithm>
#include <functional>
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
private:
  const int MOD{static_cast<int>(1e9 + 7)};

  int f(string &s, int min_sum, int max_sum) {
    int len = s.size();
    vector<vector<int>> memo(len, vector<int>(min(max_sum, 9 * len) + 1, -1));
    // return: 满足条件个数res
    // sum: 数位之和
    std::function<int(int, int, bool)> find = [&](int idx, int sum,
                                                  bool is_limit) -> int {
      if (sum > max_sum) {
        return 0;
      }
      if (idx == len) {
        return sum >= min_sum; // 只在结束时比较<:过程中小于没有意义
      }
      // 若idx==len,会超过memo范围
      if (!is_limit && memo[idx][sum] > -1) {
        return memo[idx][sum];
      }
      int res = 0;
      int up = is_limit ? s[idx] - '0' : 9;
      for (int i = 0; i <= up; i++) {
        res = (res + find(idx + 1, sum + i, is_limit && (s[idx] - '0' == i))) %
              MOD;
      }
      if (!is_limit) {
        memo[idx][sum] = res;
      }
      return res;
    };

    return find(0, 0, true);
  }

public:
  // 返回满足条件的数字数量： nums1 <= i <= nums2,
  //                        min_sum <= digitsum(i) <= max_sum
  int count(string num1, string num2, int min_sum, int max_sum) {
    int ans = 0;
    int ans1 = f(num1, min_sum, max_sum);
    int ans2 = f(num2, min_sum, max_sum);
    int sum = 0;
    for (char c : num1) {
      sum += c - '0';
    }
    // nums1本身可能并非满足条件
    ans = (ans2 - ans1 + MOD) + (sum <= max_sum && sum >= min_sum);
    ans = ans % MOD;
    return ans;
  }
};

int main() {
  Solution sol;

  printInt("ans: 972251498 -- ",
           sol.count("4859473643", "30159981595", 58, 59));
  // 1:{1}, size = 1
  // 12: {1,2,3,4,5,6,7,8,10,11,12}, size = 11
  printInt("ans: 11 -- ", sol.count("1", "12", 1, 8));
  return 0;
}