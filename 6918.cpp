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
private:
  string comb(string &a, string &b) {
    int n0 = a.size(), n1 = b.size();
    int s0 = 0;
    for (; s0 < n0; s0++) {
      int i = s0;
      for (int j = 0; i < n0 && j < n1; i++, j++) {
        if (a[i] != b[j]) {
          break;
        }
      }
      if (i == n0) {
        break;
      }
    }
    return a + b.substr(n0-s0);
  }

public:
  string minimumString(string a, string b, string c) {
    // a + b, 选择重合部分最大的组合
    // 重合部分一样，则选择字典序小的组合
    // 2. 排序，先组合小的
    vector<string> v{a, b, c};
    auto comp = [](string &a, string &b) {
      if (a.size() != b.size()) {
        return a.size() < b.size();
      }
      return a < b;
    };
    std::sort(v.begin(), v.end());
    string ans;
    string x0 = comb(v[0], v[1]);
    string x1 = comb(v[1], v[0]);
    ans = comp(x1, x0) ? x1 : x0;
    x0 = comb(ans, v[2]);
    x1 = comb(v[2], ans);
    ans = comp(x1, x0) ? x1 : x0;
    return ans;
  }
};

int main() {
  Solution sol;
  cout << "ans: ba -- " << sol.minimumString("ba", "a", "b");
  cout << "ans: ca -- " << sol.minimumString("ca", "a", "a");
  return 0;
}