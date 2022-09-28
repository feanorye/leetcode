#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::string;
using std::vector;
class MyLinkedList {
private:
  struct NODE {
    int val;
    struct NODE *next;
    NODE(int v) : val(v), next(nullptr) {}
  };
  NODE *head;

public:
  MyLinkedList() {
    head = new NODE(-1);
    head->next = nullptr;
  }

  void print() {
    NODE *it = head;
    while (it) {
      cout << it->val << " ";
      it = it->next;
    }
    cout << endl;
  }
  int get(int index) {
    NODE *it = head;
    for (int i = -1; i < index; i++) {
      if (it->next == nullptr) {
        return -1;
      }
      it = it->next;
    }
    return it->val;
  }

  void addAtHead(int val) {
    NODE *ins_node = new NODE(val);
    ins_node = head->next;
    head->next = ins_node;
  }

  void addAtTail(int val) {
    NODE *p = head;
    while (p->next != nullptr)
      p = p->next;
    p->next = new NODE(val);
  }

  void addAtIndex(int index, int val) {
    NODE *p = head;
    for (int i = -1; i < index - 1; i++) {
      if (p->next == nullptr) {
        return;
      }
      p = p->next; // only p is sure not null
    }
    NODE *tmp = p->next;
    p->next = new NODE(val);
    p->next->next = tmp;
  }

  void deleteAtIndex(int index) {
    NODE *p = head;

    for (int i = -1; i < index - 1; i++) {
      if (p->next == nullptr) {
        return;
      }
      p = p->next;
    }
    NODE *del_node = p->next; // Maybe null
    if (del_node == nullptr)
      return;
    p->next = p->next->next;
    delete del_node;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> ex1;
  return 0;
}