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
  // 以两个为单位，互相交换
  ListNode *swapPairs(ListNode *head) {
    ListNode *ans = new ListNode(0), *pre = ans;
    // [1,2,3,4,5] -> [2,1,4,3,5]
    while (head != nullptr && head->next != nullptr) {
      ListNode * next_cp = head->next->next;
      pre->next = head->next;  // null -> 2
      pre->next->next = head; // 2->1
      pre = head; //当前head->next未定
      head = next_cp; // 可能null / 1 / 2
    }
    // if null: pre->next = null
    //       1:           = 1
    pre->next = head;
    pre = ans->next;
    delete ans;
    return pre;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}