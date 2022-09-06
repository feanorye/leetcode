#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
public:
  // rotate array
    int minArray(vector<int>& numbers) {
      if (numbers.size() == 0)
        return -1;
        int ans = numbers[0];
      for (auto v : numbers)
        ans = min(ans, v);
      return ans;
        
    }
};

int main() {
    Solution sol;
}