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
  // 归并排序
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *slow = head, *fast = head->next;
    // 快慢指针：快指针是慢指针的双倍速度
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *tmp = slow->next;
    slow->next = nullptr;
    ListNode *left = sortList(head);
    ListNode *right = sortList(tmp);
    ListNode *h = new ListNode(0);
    ListNode *res = h;
    while (left != nullptr && right != nullptr) {
      if (left->val < right->val) {
        h->next = left;
        left = left->next;
      } else {
        h->next = right;
        right = right->next;
      }
      h = h->next;
    }
    h->next = left == nullptr ? right : left;
    return res->next;
  }
  // 迭代版归并：每层比较个数一样，增加层数双倍个数
  ListNode *sortList2(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    int scnt = 1;
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *pre, *h = head;
    int len = 0;
    while (h != nullptr) {
      len++;
      h = h->next;
    }

    while (scnt < len) {
      pre = res;
      h = res->next;
      while (h != nullptr) {
        // h: 第一个未排序元素，作为第一批元素
        ListNode *left = h;
        ListNode *lpre = nullptr;
        for (int i = 0; i < scnt && h != nullptr; i++) {
          lpre = h;
          h = h->next;
        }
        lpre->next = nullptr;
        // h: 第二批元素开始位置
        ListNode *right = h;
        ListNode *rpre = nullptr;
        for (int i = 0; i < scnt && h != nullptr; i++) {
          rpre = h;
          h = h->next;
        }
        rpre->next = nullptr;
        // h: 新的未排序元素或者末尾空指针
 
        // merge
        while (left && right) {
          if (left->val < right->val) {
            pre->next = left;
            left = left->next;
          } else {
            pre->next = right;
            right = right->next;
          }
          pre = pre->next;
        }
        pre->next = left == nullptr ? right : left;
        // move pre to last sorted element
        while (pre->next != nullptr) {
          pre = pre->next;
        }
      }
      scnt *= 2;
    }
    return res->next;
  }
};

int main() {
  Solution sol;
  vector<int> ex1 = {4, 1, 2, 3};
  ListNode *head = createList(ex1);
  sol.sortList2(head);
  return 0;
}