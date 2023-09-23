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
  int minSubarray(vector<int> &nums, int p) {
    // s[r] - s[l] = sum % p
    // (s[r] - sum) % p = s[l] % p
    // ((s[r] - sum) % p + p)%p 可以保证为正数
    int n = nums.size();
    vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 0; i < n; i++) {
      // DUE: (a + b) mod p = ((a %p) + (b%p)) %p
      // AND: a mod p mod p = a mod p
      // (a mod p + b) % p = (a mod p + b mod p) % p
      s[i + 1] = (s[i] + nums[i]) % p;
    }
    // 实际上相当于(a1 + a2 + ...) mod p
    int sum = s[n];
    map<int, int> last;
    int ans = n;
    for (int i = 0; i < n; i++) {
      last[s[i]] = i;
      // ((s[r] - sum(a)) % p + p)% p
      // 实际上 （(s[r] mod p - sum(a) mod p) mod p + p) mod p
      // 发现s[r] mod p必 >= 0, 则s[r] mod p - sum(a) mod p > -p
      // 所以可以 s[r] mod p - sum(a) mod p + p) mod p
      auto it = last.find((s[i] - sum + p) % p);
      if (it != last.end()) {
        // note: 前3位 - 前2位 = 1
        ans = min(ans, i - it->second);
      }
    }
    return ans < n ? ans : -1;
  }
};

int main() {
  Solution sol;
  return 0;
}