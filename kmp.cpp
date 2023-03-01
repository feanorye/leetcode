#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::vector;

vector<int> buildNext(string p){
  int m = p.size(), j = 0;
  vector<int> ans(m,-1);
  int t = -1;
  while(j < m){
    if(0 > t || p[j] == p[t]){
      t++;
      j++;
      ans[j] = t;
    }else{
      t = ans[t];
    }
  }
  return (ans);
}

int main(){
  string p = "000010";
  auto ans = buildNext(p);
  // string str = fmt::format("ans: {}\n",a);
  // cout << str;
  int n = ans.size();
  for(int i = 0; i < n; i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  for(auto e : ans){
    cout << e << " ";
  }
  return 0;
}