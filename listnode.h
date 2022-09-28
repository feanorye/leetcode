#include <iostream>
#include <string_view>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
using std::cout;
using std::endl;
using std::vector;
ListNode *createList(vector<int> &list) {
  ListNode *head = new ListNode(0);
  ListNode *p = head;
  for (auto x : list) {
    ListNode *node = new ListNode(x);
    p->next = node;
    p = node;
  }
  p = head->next;
  delete head;
  return p;
}
void deleteList(ListNode *head) {
  while (head) {
    ListNode *p = head->next;
    delete head;
    head = p;
  }
}
void display(ListNode *head) {
  cout << "List: ";
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
// print vector
void printV(vector<int> mat, const char * str) {
  cout << str << " -- [";
  for (auto v : mat) {
    cout << v << " ";
  }
  cout << "\b]"<< endl;
}

void printl(vector<vector<int>> &mat) {
  int m = mat.size(), n = mat[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}