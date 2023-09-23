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

// 带权并查集 -> 图论
class UnionFind {
private:
  vector<int> _parents;
  vector<double> _weights;
  map<string, int> _dic;
  int _next_id;

public:
  UnionFind() : _next_id(0) {}
  /**
   * @return idx of var
   */
  int insert(string &var) {
    if (_dic.count(var) > 0) {
      return _dic.at(var);
    }
    _dic[var] = _next_id;
    _parents.push_back(_next_id);
    _weights.push_back(1);
    return _next_id++;
  }
  int getid(string &var) const{
    if (_dic.count(var) > 0) {
      return _dic.at(var);
    }
    return -1;
  }
  /**
   * @param weight: x / y
   *   rootx ------> rooty
   *     /             \
   *    weight[x]     weight[y]
   *     |               |
   *     x   ---val----  y
   */
  void merge(int idx, int idy, double val) {
    int rootx = find(idx);
    int rooty = find(idy);
    if (rootx == rooty) {
      return;
    }
    _parents[rootx] = rooty;
    _weights[rootx] = _weights[idy] * val / _weights[idx];
  }
  /**
   * @return id of x's parent
   *     a(1)<--b(2)<--c(3)<--d(4)
   *     a(1)<--b(2)
   *         <--c(3 * 2)
   *         <--d(4 * 6)
   */
  int find(int x) {
    if (_parents[x] != x) {
      int old_p = _parents[x];
      _parents[x] = find(_parents[x]);
      _weights[x] = _weights[x] * _weights[old_p];
    }
    return _parents[x];
  }
  /**
  ** @return x / y
  */
  double is_connected(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) {
      return _weights[x] / _weights[y];
    }
    return -1;
  }
};
class Solution {
public:
  /**
   * @param equations: {[x1, y1], [x2, y2]...}
   * @param values: {x1/y1, x2/y2, ...}
   */
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    UnionFind uf1;
    vector<double> ans;
    int len = equations.size();
    for (int i = 0; i < len; i++) {
      string x = equations[i][0];
      string y = equations[i][1];
      int idx = uf1.insert(x);
      int idy = uf1.insert(y);
      uf1.merge(idx, idy, values[i]);
    }
    for (auto q : queries) {
      int idx = uf1.getid(q[0]);
      int idy = uf1.getid(q[1]);
      if (idx == -1 || idy == -1) {
        ans.push_back(-1);
      } else {
        ans.push_back(uf1.is_connected(idx, idy));
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}