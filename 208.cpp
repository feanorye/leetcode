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
// 前缀树：智能补全
// 类似页表
class Trie {
  Trie *next[26];
  bool isword; //比如app/apple/a/，相同前缀，不同单词
public:
  Trie() {
    for (auto &p : next) {
      p = nullptr;
    }
    isword = false;
  }
  ~Trie() {
    for (auto p : next) {
      if (p != nullptr) {
        delete p;
      }
    }
  }

  void insert(string word) {
    // 通过root跳转不同实例
    Trie *root = this;
    for (char c : word) {
      int idx = c - 'a';
      if (root->next[idx] == nullptr) {
        root->next[idx] = new Trie();
      }
      // 必须使用root->next，否则会使用当前实例next
      root = root->next[idx]; //跳转到下个trie
    }
    // root所指为叶子节点，当前所有next数组全为nullptr
    root->isword = true;
  }

  bool search(string word) {
    Trie *root = this;
    for (char c : word) {
      int idx = c - 'a';
      if (root->next[idx] == nullptr)
        return false;
      root = root->next[idx];
    }
    // assume: insert "apple", search "app"
    return root->isword;
  }

  bool startsWith(string prefix) {
    Trie *root = this;
    for (char c : prefix) {
      int idx = c - 'a';
      if (root->next[idx] == nullptr)
        return false;
      root = root->next[idx];
    }
    return true;
  }
};

int main() {
  string word{"zhang"}, prefix{"zha"};
  Trie *obj = new Trie();
  obj->insert(word);
  bool param_2 = obj->search(word);
  bool param_3 = obj->startsWith(prefix);
  obj->insert(prefix);
  bool param_4 = obj->search(prefix);

  return 0;
}