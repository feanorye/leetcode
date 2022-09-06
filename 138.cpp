#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
      //迭代法：
      // A - B - C
      // A - A' - B - B' - C - C'
      for (Node *node = head; node != NULL; node = node->next->next) {
        Node *new_node = new Node(node->val);
        new_node->next = node->next;
        node->next = new_node;
      }
      for (Node *node = head; node != NULL; node = node->next->next) {
        node->next->random = (node->random == NULL) ? NULL : node->random->next;
      }
      Node *new_head = head->next;
      //After changed node->next, step should change to: node = node->next
      for (Node *node = head; node != NULL; node = node->next) {
        Node *new_node = node->next;
        node->next = new_node->next;
        new_node->next = (node->next == NULL)? NULL: node->next->next;
      }
      return new_head;
    }
};
int main() {//fail to create 
  vector<Node *> arr;
  int ha[5][2] = {{7,NULL},{13,0},{11,4},{10,2},{1,0}};
  for (auto [k, p] : ha) {
    Node *new_node = new Node(k);
    arr.push_back(new_node);
  }
  arr.push_back(NULL); // add to terminal
  int i = 0;
  for (auto [k, p] : ha) {
    arr[i]->next = arr[i+1];
    if (p == NULL) {
      arr[i++]->random = nullptr;
    } else {
    arr[i++]->random = arr[p];
    }
  }
  Solution sol;
  sol.copyRandomList(arr[0]);
  return 0;
}