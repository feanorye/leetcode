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
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      vector<int> ans;
      if (k < 1)
        return ans;
      for (int i = 0; i < k; i++) {
        ans.push_back(arr[i]);
      }
      int len = arr.size();
      int ind = 0;
      bool changed = true;

      auto maxv = [&k, &ans, &ind, &changed]() {
        if (!changed)
          return ind;
        ind = 0;
        int max_val = ans[0];
        for (int i = 1; i < k; i++) {
          if (ans[i] > max_val) {
            ind = i;
            max_val = ans[i];
          }
        }
        changed = false;
        return ind;
      };

      for (int i = k; i < len; i++) {
        int index = maxv();
        if (ans[index] > arr[i]) {
          changed = true; 
          ans[index] = arr[i];
        }
      }
      return ans;
    }
};

int main() {
  Solution sol;
  vector<int> ex1 = {0, 0, 0, 2, 0, 5};
  sol.getLeastNumbers(ex1, 0);
  return 0;
}