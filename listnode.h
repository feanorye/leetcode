#include <corecrt.h>
#include <iostream>
#include <queue>
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
using std::queue;
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
template <typename Elem> void printV(vector<Elem> mat, const char *str) {
  cout << str << " [ ";
  for (auto v : mat) {
    cout << v << ",";
  }
  cout << "\b ]" << endl;
}

void printl(vector<vector<int>> &&mat) {
  size_t m = mat.size();
  if (m == 0)
    cout << "[[]]\n";
  size_t n = mat[0].size();
  cout << endl << "matrix: " << m << " * " << n << endl;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < mat[i].size(); j++) {
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// use -1 represent NULL
TreeNode *Create_tree(vector<int> &data) {
  auto n = data.size();
  if (n == 0 || data[0] == -1)
    return nullptr;
  TreeNode *root = new TreeNode(data[0]);
  queue<TreeNode *> q;
  q.push(root);
  for (size_t i = 1; i < n; i++) {
    TreeNode *p = q.front();
    q.pop();
    TreeNode *lchild = nullptr, *rchild = nullptr;

    if (data[i] != -1) {
      lchild = new TreeNode(data[i]);
      q.push(lchild);
    }
    p->left = lchild;
    if (++i >= n)
      break;
    if (i < n && data[i] != -1) {
      rchild = new TreeNode(data[i]);
      q.push(rchild);
    }
    p->right = rchild;
  }
  return root;
}

/* void print_tree(TreeNode *root) {
  if (root == nullptr) {
    cout << "NULL ";
    return;
  }
} */