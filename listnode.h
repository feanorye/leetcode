#include <iostream>
#include <string>
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
template<typename Elem>
void printV(vector<Elem> mat, const char *str) {
  cout << str << " [ ";
  for (auto v : mat) {
    cout << v << ",";
  }
  cout << "\b ]" << endl;
}

void printl(vector<vector<int>> mat) {
  int m = mat.size();
  if (m == 0)
    cout << "[[]]\n";
  int n = mat[0].size();
  cout << endl << "matrix: " << m << " * " << n << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

void printInt(const char *str, int num) { cout << str << num << endl; }
void printStrA(vector<std::string> &&mat) {
  cout << '[';
  for (auto str : mat)
    cout << str << ",";
  cout << "\b]\n";
}