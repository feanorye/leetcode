#include "listnode.h"
#include <algorithm>
#include <corecrt.h>
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
  vector<int> primes{0};

public:
  Solution() {
    const int MX = 1000;
    vector<int> is_prime(MX, 1);
    for (int i = 2; i < MX; i++) {
      if (is_prime[i] == 1) {
        primes.push_back(i);
      }
      for (int j = i; j < MX / i; j++) {
        is_prime[i * j] = 0;
      }
    }
  }
  bool primeSubOperation(vector<int> &nums) {
    size_t len = nums.size();
    for (int i = len - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1])
        continue;
      auto it =
          std::upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]);
      if (it == nums.end())
        return false;
      nums[i] -= (*it);
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> ex3 = {1000, 1000, 1000, 1000, 1000};
  printInt("ans: false -- ", sol.primeSubOperation(ex3));
  vector<int> ex2 = {5, 8, 3};
  printInt("ans: false -- ", sol.primeSubOperation(ex2));

  vector<int> ex1 = {4, 9, 6, 10};
  printInt("ans: true -- ", sol.primeSubOperation(ex1));
  return 0;
}