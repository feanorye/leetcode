#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;

    while (fast) {
      if (fast->next != NULL)
        fast = fast->next->next;
      else
        fast = NULL;
      slow = slow->next;
      if (fast == slow)
        break;
    }
    if (fast == NULL)
      return nullptr;
    fast = head;
    //此处，fast开始，每次步进1
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};

int main() { Solution sol; }