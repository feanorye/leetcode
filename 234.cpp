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
  // 反转链表+快慢指针
  bool isPalindrome(ListNode *head) {
    ListNode *half, *hp = head;
    half = halfList(head);
    ListNode *half2 = reverseList(half->next);
    half->next = half2;
    bool ans = true;
    while (half2 != nullptr) {
      if (hp->val != half2->val) {
        ans = false;
        break;
      }
      hp = hp->next;
      half2 = half2->next;
    }
    half->next = reverseList(half->next);
    return ans;
    }
  ListNode *halfList(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      // index_fast = 2 * index_slow
      // odd size: index_fast = n - 1, index_slow = (n - 1)/2
      // even size: ind_f = n - 2, ind_s = (n - 2) / 2
      slow = slow->next;
      fast = fast->next->next;
    }
    // odd: (0,slow).size = (n+1)/2
    // even:(0,slow).size = n / 2
    // slow point to upper node of medium
    return slow;
  }
  ListNode * reverseList(ListNode *head) {
    ListNode *prev = nullptr, *cur = head;
    while (cur != nullptr) {
      ListNode *tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {1,2,2,1};
  ListNode *h = createList(ex1);
  cout << "ans: true -- " << sol.isPalindrome(h);
  deleteList(h);
  return 0;
}