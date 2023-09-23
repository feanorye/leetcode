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

class LRUCache {
  // 双向链表
  struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v) {
      prev = nullptr;
      next = nullptr;
    }
  };
  map<int, Node *> dic;
  int _size;
  Node *head, *tail;

public:
  LRUCache(int capacity) : _size(capacity) {
    // create _size+2 nodes
    head = new Node(-1, -1);
    Node *p, *pre = head;
    for (int i = 0; i < capacity; i++) {
      p = new Node(-1, -1);
      pre->next = p;
      p->prev = pre;
      pre = p;
    }
    tail = new Node(-1, -1);
    pre->next = tail;
    tail->prev = pre;
  }

  int get(int key) {
    if (dic.count(key) > 0) {
      refresh(dic[key]);
      return dic[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (dic.count(key) > 0) {
      dic[key]->val = value;
      refresh(dic[key]);
      return;
    }
    // insert new key, val
    if (dic.size() >= this->_size) {
      // pointer prev of tail
      dic.erase(this->tail->prev->key);
    }
    Node *ele = this->tail->prev;
    ele->key = key;
    ele->val = value;
    dic[key] = ele;
    refresh(ele);
  }
  void refresh(Node *p) {
    Node *pre = p->prev;
    pre->next = p->next;
    p->next->prev = pre;
    // add to head
    p->prev = head;
    p->next = head->next;
    head->next = p;
    p->next->prev = p;
  }
};

int main() {
  LRUCache cc(2);
  cc.put(1, 1);
  cc.put(2, 2);
  cout << "ans: 1 -- " << cc.get(1) << endl; // 返回 1
                                             // 
  cc.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  cout << "ans: -1 -- " << cc.get(2) << endl; // 返回 -1 (未找到)
                                              // 
  cc.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  cout << "ans: -1 " << cc.get(1) << endl;    // 返回 -1 (未找到)
  cout << "ans: 3 " << cc.get(3) << endl;    // 返回 3
  cout << "ans: 4 " << cc.get(4) << endl;    // 返回 4

  return 0;
}