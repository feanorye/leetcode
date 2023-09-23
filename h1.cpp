#include <algorithm>
#include <charconv>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
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

int main() {
  // [!, @, # ]
  int a[3][3] = {{0, 13, 4}, {13, 7, 20}, {4, 20, 5}};
  map<char, int> mc;
  mc['!'] = 0;
  mc['@'] = 1;
  mc['#'] = 2;
  int n = 0;
  string s;

  cin >> n >> s;
  cout << "n:" << n << " s:" << s << endl;
  auto split = [n](string &s) {
    vector<string> ans;
    int i = 0;
    for (; i < n; i++) {
      if (s[i] == '+')
        break;
    }
    ans.push_back(s.substr(0, i));
    ans.push_back(s.substr(i + 1));
    return ans;
  };
  vector<string> fom = split(s);
  for (auto v : fom) {
    cout << v << endl;
  }
  // 返回小数个位+1，无小数点返回0
  auto findDot = [](string &st) {
    for (int i = 0; i < st.size(); i++)
      if (st[i] == '.')
        return st.size() - i;
    return static_cast<size_t>(0);
  };
  string t1 = "123.23", t2 = "123";
  cout << t1 << ": " << findDot(t1) << endl;
  cout << t2 << ": " << findDot(t2) << endl;
  int d0 = findDot(fom[0]);
  int d1 = findDot(fom[1]);
  int make_up = abs(d1 - d0);
  string &md = d0 > d1 ? fom[1] : fom[0];
  for (int i = 0; i < make_up; i++) {
    md.push_back('0');
  }
  n = fom[0].size();
  int c = 0;
  string res;
  for (int i = n - 1; i >= 0; i--) {
    char c0 = fom[0][i], c1 = fom[1][i];
    if (c0 == '.') {
      res.push_back('.');
      continue;
    }
    int tmp = 0;
    if (c0 >= '0' && c0 <= '9')
      tmp = c0 - '0' + c1 - '0' + c;
    else {
      int row = mc[c0], col = mc[c1];
      tmp = a[row][col] + c;
    }
    c = tmp / 10;
    tmp = tmp % 10;
    // todo: 当其中一个无小数点时，'0' - 2刚好是小数点
    res.push_back(static_cast<char>(tmp + '0'));
    cout << c0 << "+" << c1 << "=" << tmp << "..." << c << endl;
  }
  if (c > 0)
    res.push_back(static_cast<char>(c + '0'));
  std::reverse(res.begin(), res.end());
  cout << "res:" << res << endl;
  int d = 0;
  // todo: 最后发生进位
  if (findDot(res) > 0)
    d = 1;
  cout << std::setprecision(res.size() - d) << std::stof(res) << endl;

  return 0;
}