#include "tree.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (p1 != p2) {
      p1 = (p1 == nullptr) ? headB : p1->next;
      p2 = (p2 == nullptr) ? headA : p2->next;
    }
    if (p1 == nullptr)
      return nullptr;
    return p1;
  }
};

int main() {
  Solution sol;
  sol.getIntersectionNode(>, int *headB);
}