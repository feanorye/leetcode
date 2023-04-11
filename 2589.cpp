#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
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

class Solution {
public:
  struct Item {
    int l, r, t;
    // todo: 为什么必须小于， <=出错？可能重排序过多
    bool operator<(const Item &other) const { return r < other.r; }
  };

  int findMinimumTime2(const vector<vector<int>> &tasks) {
    const int n = tasks.size();
    // 将任务按右端点排序
    // 同时将区间转化为左闭右开形式，方便处理
    vector<Item> items;
    items.reserve(n);
    for (const auto &e : tasks)
      items.push_back({e[0], e[1] + 1, e[2]});
    sort(items.begin(), items.end());
    // 用栈维护被选取点组成的区间，必定不可能重合的区间，若连接紧密还会合并
    // 此时 t 参数表示的不是单个区间的长度
    // 而是从栈底到当前项之间的区间的长度和(前缀和)
    // 这样可以快速计算任意一段区间的长度和
    vector<Item> stk = {{-1, -1, 0}};
    int ans = 0;
    for (const auto [l, r, t] : items) {
      // 二分找到区间：有可能和当前区间重合的已分配区间
      const auto it = prev(partition_point(
          stk.begin(), stk.end(), [l = l](const Item &e) { return e.l <= l; }));
      // 前缀和相减得到区间长度和：已分配长度 - [0:可能重合]长度 + 重合长度
      // it->r 如果大于 l, 则必定重合
      const int cnt = stk.back().t - it->t + max(it->r - l, 0);
      int d = t - cnt;
      if (d <= 0)
        continue;
      ans += d;
      // 合并区间
      // d 维护了加入的最左侧点离当前区间右端点的距离
      // 如果 [r - d, r) 与栈顶区间相交（或没有空隙，可合并）
      // 就将栈顶区间并入，并修改 d 的值
      for (; r - stk.back().r <= d; stk.pop_back())
        d += stk.back().r - stk.back().l;
      // 合并结束
      // 加入新的区间 [r - d, r)
      // 相当于全部剩余元素放到了右边
      stk.push_back({r - d, r, stk.back().t + d});
    }
    return ans;
  }
  int findMinimumTime(const vector<vector<int>> &tasks) {
    vector<Item> item;
    item.reserve(tasks.size());
    for (auto elem : tasks) {
      item.push_back({elem[0], elem[1]+1, elem[2]});
    }
    std::sort(item.begin(), item.end());
    vector<Item> stack;
    //   存储已分配区间
    //   此时t为已分配前缀和，这样可以求出任意区间已分配长度
    stack.push_back({-1, -1, 0});
    long long ans = 0;
    for (auto [left, right, time] : item) {
      //   找到可能重合区间左边界
      auto it = std::prev(
          std::partition_point(stack.begin(), stack.end(),
                               [left = left](Item &e) { return e.l <= left; }));
      int cnt = stack.back().t - it->t + max(it->r - left, 0);
      int d = time - cnt;
      if (d <= 0)
        continue;
      ans += d;
      for (; right - stack.back().r <= d;) {
        d += (stack.back().r - stack.back().l);
        stack.pop_back();
      }
      stack.push_back({right-d, right, stack.back().t+d});
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = {{2, 3, 1}, {4, 5, 1}, {1, 5, 2}};
  cout << sol.findMinimumTime(ex1);
  return 0;
}