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
using std::priority_queue;

class Solution {
public:
  struct CMP{
    bool operator()(ListNode *l, ListNode * r) {
      return l->val > r->val;
    }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ans = new ListNode(-1), *tail = ans;
    priority_queue<ListNode *, vector<ListNode *>, CMP> pq;
    for (auto elem : lists) {
      if (elem != nullptr)
        pq.push(elem);
    }
    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();
      if (node->next != nullptr) {
        pq.push(node->next);
      }
      tail->next = node;
      tail = node;
    }
    tail = ans->next;
    delete ans;
    return tail;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}