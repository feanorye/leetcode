#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>


using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
using std::unordered_map;
class TopVotedCandidate {
  vector<int> preTop;
  vector<int> time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
      int n0 = persons.size();
      vector<int> topArr(n0,-1);
      unordered_map<int, int> hash;
      hash[-1] = -1;
      int top = -1;
      int i = 0;
      for (auto x : persons) {
        hash[x]++;
        if(hash[x] >= hash[top])
          top = x;
        topArr[i++] = top;
      }
      this->preTop = topArr;
      this->time = times;
    }
    
    int q(int t) {
      int n = time.size();
      int l = 0, r = n - 1;
      //find time[l] <= t < time[l+1]
      while (l < r) {
        int m = l + (r - l + 1) / 2;
        // <:[m,r]
        // =:[m]
        // >:[l,m-1]
        if (time[m] <= t) {
          l = m;
        } else {
          r = m-1;
        }
      }
      return preTop[l];
    }
};

int main() {
  vector<vector<int>> ex1 = {{0,1,1,0,1},{5,10,15,23,25}};
  TopVotedCandidate sol(ex1[0],ex1[1]);
  cout << sol.q(6) << endl;
  cout << sol.q(24) << endl;
  return 0;
}