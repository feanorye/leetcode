#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
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
  const int MX = 1e5 + 1;
  const int MOD = 1e9 + 7;
  vector<int> omega;
  int pow(long long x, int n) {
    // x ^ n = x ^ 2 ^ n/2
    // x^4 = x^2^2
    // x^5 = x^2^2 * x
    long long ans = 1;
    for (; n > 0; n /= 2) {
      if (n % 2) {
        ans = ans * x % MOD;
      }
      x = x * x % MOD;
    }
    return ans;
  }

public:
  Solution() : omega(vector<int>(MX, 0)) {
    for (int i = 2; i < MX; i++) {
      if (omega[i] == 0) {
        // note: 从i开始，该处为1
        for (int j = i; j < MX; j += i) {
          omega[j]++;
        }
      }
    }
  };
  /**
   * 一开始，你的分数为 1 。你可以进行以下操作至多 k 次，目标是使你的分数最大：
   * 1. 选择一个之前没有选过的 非空 子数组 nums[l, ..., r] 。
   * 2. 从 nums[l, ..., r] 里面选择一个 质数分数 最高的元素 x
   * 3. 如果多个元素质数分数相同且最高，选择下标最小的一个。 将你的分数乘以 x 。
   * 单调栈
   */
  int maximumScore(vector<int> &nums, int k) {
    /**
     * 19,12,14,6,10,18, 30
     * 1, 2, 2, 2, 2, 2, 3
     * left: >= omega[i], right: > omega[i]
     * 0. 次数：(i - left[i]) * (right[i] - i)
     * 1. nums[i]从大到小遍历，获取对应的次数t, ans *= nums[i] ^ min(t, k)
     * 2. k -= t
     */
    int len = nums.size();
    vector<int> prime(len);
    vector<int> left(len, -1);   // 左侧>= prime[i]的最近元素
    vector<int> right(len, len); // 右侧 > prime[i]的最近元素

    for (int i = 0; i < len; i++) {
      prime[i] = omega[nums[i]];
    }

    stack<int> st;
    for (int i = 0; i < len; i++) {
      while (!st.empty() && prime[st.top()] < prime[i]) {
        right[st.top()] = i;
        st.pop();
      }
      if (!st.empty()) {
        left[i] = st.top();
      }
      st.push(i);
    }
    vector<int> idx(len);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&nums](const int left, const int right) {
      return nums[left] > nums[right];
    });
    long long ans = 1;
    int i = 0;
    while (k > 0 && i < len) {
      int j = idx[i];
      int key = nums[j];
      int rep = (right[j] - j) * (j - left[j]);
      ans = ans * pow(key, min(k, rep)) % MOD;
      k -= rep;
      i++;
    }
    return ans % MOD;
  }
};

int main() {
  Solution sol;
  vector<int> ex2{8, 3, 9, 3, 8};
  printInt("ans: 81--", sol.maximumScore(ex2, 2));
  vector<int> ex1{19, 12, 14, 6, 10, 18};
  printInt("ans: 4788 -- ", sol.maximumScore(ex1, 3));
  return 0;
}