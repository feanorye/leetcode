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

class Solution {
public:
  // 每k个元素反转顺序
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *fast = head, *slow = head;
    // 1->2->3->4->5
    // 2->1->4->3->5
    // return dummy node to point to next group
    auto reverse = [](ListNode *s0, ListNode *s1,
                      ListNode *last) -> ListNode * {
      // result list not include s1
      ListNode *s2 = nullptr, *np = nullptr, *ret = s0;
      while (s0 != s1) {
        s2 = s0->next;
        s0->next = np;
        np = s0;
        s0 = s2;
      }
      last->next = np;
      return ret;
    };
    ListNode *dummy = new ListNode(-1);
    head = dummy;
    while (fast != nullptr) {
      int i = 0;
      for (; i < k && fast != nullptr; i++) {
        fast = fast->next;
      }
      if (i != k) {
        dummy->next = slow;
        break;
      }
      dummy = reverse(slow, fast, dummy);
      slow = fast;
    }

    dummy = head;
    head = head->next;
    delete dummy;
    return head;
  }
};

int main() {
  Solution sol;
  vector<int> ex1{1, 2, 3, 4, 5};
  ListNode *head = createList(ex1);
  sol.reverseKGroup(head, 2);
  return 0;
}