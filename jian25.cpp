#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

// Definition for singly-linked list.

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;
    ListNode *ans = (l1->val < l2->val) ? l1 : l2;
    ListNode *search = (ans == l1) ? l2 : l1;
    ListNode *pre = ans;
    ListNode *front = ans;
    while (search) {
      while (front && front->val <= search->val) {
        pre = front;
        front = front->next;
      }
      if (front == nullptr) {
        pre->next = search;
        break;
      }
      ListNode *searchFront = search->next;
      // Connect Pre->search;
      // then, find search -> xxx -> front
      // search->next = front;
      pre->next = search;
      while (searchFront && searchFront->val <= front->val) {
        search = searchFront;
        searchFront = searchFront->next;
      }
      // connect xxx->front
      search->next = front;
      search = searchFront;
    }
    return ans;
  }
  // jian21
  vector<int> exchange(vector<int> &nums) {
    int len = nums.size();
    int pre = -1;
    vector<int> ans = nums;
    // 奇数，偶数 [1,2,4,5] -> [1,5,2,4]
    // pre: 偶数
    // front: 奇数
    for (int i = 0; i < len; i++) {
      if (ans[i] % 2 != 0) {
        while(pre < i && ans[++pre] % 2);
        if(pre < i){
          std::swap(ans[i], ans[pre]);
        }
      }
    }
    return ans;
  }
};
void printV(vector<int> &mat) {
  cout << "mat: ";
  for (auto v : mat) {
    cout << v << " ";
  }
  cout << endl;
}
int main() {
  Solution sol;
  vector<int> ex1 = {1, 2, 4, 7, 9, 10};
  vector<int> ex2 = {2, 3, 6, 8, 11, 15};
  vector<int> ans1 = sol.exchange(ex1);
  printV(ans1);
  ans1 = sol.exchange(ex2);
  printV(ans1);
  ListNode *h1 = createList(ex1);
  ListNode *h2 = createList(ex2);
  ListNode *ans = sol.mergeTwoLists(h1, h2);
  display(ans);
  deleteList(ans);
  return 0;
}