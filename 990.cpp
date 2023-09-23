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

class UnionFind {
private:
  map<string, int> _dic;
  vector<int> _parents;
  int _next_id = 0;

public:
  int insert(const string &var) {
    if (_dic.count(var) > 0) {
      return _dic.at(var);
    }
    _parents.push_back(_next_id);
    _dic[var] = _next_id;
    return _next_id++;
  }
  int getId(const string &var) {
    if (_dic.count(var) > 0) {
      return _dic.at(var);
    }
    return -1;
  }
  int find(int x) {
    if (_parents[x] != x) {
      _parents[x] = find(_parents[x]);
    }
    return _parents[x];
  }
  /* @brief 只存在等价关系 */
  void merge(int idx, int idy) {
    int rootx = find(idx);
    int rooty = find(idy);
    if (rootx == rooty) {
      return;
    }
    _parents[rootx] = rooty;
  }
  bool is_connected(int idx, int idy) {
    int rootx = find(idx);
    int rooty = find(idy);
    return rootx == rooty;
  }
};

class Solution {
private:
  string find_var(string &s, int &pos, int len,
                  std::function<bool(char c)> const &pred) {
    int a1 = pos;
    for (; pos < len; pos++) {
      if (pred(s[pos])) {
        break;
      }
    }
    return s.substr(a1, pos - a1);
  }

public:
  /**
   * @param equations: {"a==b", "a!=b"}
   */
  bool equationsPossible(vector<string> &equations) {
    vector<string> neq_vec;
    UnionFind uf1;
    auto not_var = [](char c) -> bool { return c > 'z' || c < 'a'; };
    auto not_sym = [](char c) -> bool { return c != '=' && c != '!'; };
    // 先处理等式
    for (auto eq : equations) {
      if (eq.find('!') != string::npos) {
        neq_vec.emplace_back(eq);
        continue;
      }
      int pos = 0;
      int len = eq.size();
      string v1 = find_var(eq, pos, len, not_var);
      find_var(eq, pos, len, not_sym);
      string v2 = find_var(eq, pos, len, not_var);
      int x = uf1.insert(v1);
      int y = uf1.insert(v2);
      uf1.merge(x, y);
    }

    for (auto eq : neq_vec) {
      int pos = 0;
      int len = eq.size();
      string v1 = find_var(eq, pos, len, not_var);
      find_var(eq, pos, len, not_sym);
      string v2 = find_var(eq, pos, len, not_var);
      int x = uf1.insert(v1);
      int y = uf1.insert(v2);
      if (uf1.is_connected(x, y)) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  vector<string> ex1{"a==b", "b!=a"};
  printInt("ans: false -- ", sol.equationsPossible(ex1));
  return 0;
}