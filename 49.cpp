#include "listnode.h"
#include <algorithm>
#include <array>
#include <corecrt.h>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::array;
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
using std::unordered_map;
using std::vector;
class Solution {
public:
  vector<vector<string>> groupAnagrams2(vector<string> &strs) {
    // 自定义对 array<int, 26> 类型的哈希函数
    auto arrayHash =
        [fn = std::hash<int>{}](const array<int, 26> &arr) -> size_t {
      return std::accumulate(
          arr.begin(), arr.end(), 0u,
          [&](size_t acc, int num) { return (acc << 1) ^ fn(num); });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(
        0, arrayHash);
    for (string &str : strs) {
      array<int, 26> counts{};
      int length = str.length();
      for (int i = 0; i < length; ++i) {
        counts[str[i] - 'a']++;
      }
      mp[counts].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.emplace_back(it->second);
    }
    return ans;
  }
  // 聚类：相同字符，不同顺序
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // todo:不加const会出错
    auto arrayHash =
        [fn = std::hash<int>{}](const array<int, 26> &arr) -> size_t {
      // [&]：capture fn
      return std::accumulate(
          arr.begin(), arr.end(), 0u,
          [&](size_t acc, int num) { return (acc << 1) ^ fn(num); });
    };
    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(
        0, arrayHash);
    vector<vector<string>> ans;
    for (string s : strs) {
      array<int, 26> arr;
      arr.fill(0);
      for (char c : s) {
        arr[c - 'a']++;
      }
      mp[arr].emplace_back(s);
    }
    for (auto [k, v] : mp) {
      ans.emplace_back(v);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<string> ex1{"eat", "tea", "tan", "ate", "nat", "bat"};
  printStrA2(sol.groupAnagrams2(ex1));
  return 0;
}