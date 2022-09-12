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
using std::string;
class Solution {
public:
  string minNumber(vector<int> &nums) {
    vector<string> ans;
    for(auto x : nums)
      ans.push_back(std::to_string(x));
    auto cmp = [](string &s1, string &s2) { return s1 + s2 < s2 + s1; };
    std::sort(ans.begin(), ans.end(), cmp);
    string res;
    for (auto s : ans)
      res.append(s);
    return res;
  }
  
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}