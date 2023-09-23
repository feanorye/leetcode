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

using std::cin;
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

class solution {
private:
  map<char, int> transfer;

public:
  solution() {
    string a1[2] = {{"bpdq"}, {"nu"}};
    int i = 1;
    for (string &s : a1) {
      for (char c : s) {
        transfer[c] = i;
      }
      i++;
    }
  }
  bool test(string &str) {
    /**
     1. 拆分：w{v,v}, m{n,n}注意n可以等价为u
     2. 对称：b{d}, p{q}
     3. 旋转：b{q}, d{p}, n{u}
     -> 等价：{b,p,q,d}, {n,u}
     eg.1 uuyxxym, 如果直接拆分，似乎可以简化？
     */
    int n = str.size();
    int l = n / 2;
    int r = n / 2;
    if (n % 2 == 0) {
      l--;
    }
    for (; l >= 0; l--,r++) {
      if (str[l] != str[r]) {
        if (transfer.count(str[l]) && transfer.count(str[r]) &&
            transfer[str[l]] == transfer[str[r]]) {
          continue;
        }
        return false;
      }
    }
    return true;
  }
};

int main() {
  solution sol;
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    string decompress;
    for (char c : str) {
      if (c == 'm') {
        decompress.push_back('n');
        decompress.push_back('n');
      } else if (c == 'w') {
        decompress.push_back('v');
        decompress.push_back('v');
      } else {
        decompress.push_back(c);
      }
    }
    if (sol.test(decompress)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}