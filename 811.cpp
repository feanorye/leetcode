#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::stoi;
using std::string;
using std::vector;

class Solution {
private:
  // return matched upper part of str
  vector<string> split_up(string &str, char c) {
    vector<string> ans;
    string e1;
    int start = 0;
    for (int i = 0; i < (int)str.size(); i++) {
      if (str[i] == c) {
        e1 = str.substr(start, i - start);
        ans.push_back(e1);
        start = i + 1;
      }
    }
    ans.emplace_back(str.substr(start));

    return ans;
  }
  vector<string> split_down(string &str, char c) {
    vector<string> ans;
    string e1;
    for (int i = 0; i < (int)str.size(); i++) {
      if (str[i] == c) {
        e1 = str.substr(i + 1);
        ans.push_back(e1);
      }
    }
    return ans;
  }

public:
  vector<string> subdomainVisits2(vector<string> &cpdomains) {
    map<string, int> hash;
    vector<string> ans;
    int len = cpdomains.size();
    for (int i = 0; i < len; i++) {
      vector<string> parse = split_up(cpdomains[i], ' ');
      // printStrA(parse);
      int count = stoi(parse[0]);
      // cout << parse[1] << ": " << count << endl;
      hash[parse[1]] += count;
      parse = split_down(parse[1], '.');
      int n = parse.size();
      for (int j = 0; j < n; j++) {
        hash[parse[j]] += count;
      }
    }
    for (auto &[key, val] : hash) {
      ans.emplace_back(std::to_string(val) + " " + key);
    }
    // printV(ans, "string mat:");
    return ans;
  }
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    std::unordered_map<string, int> hash;
    vector<string> ans;
    int len = cpdomains.size();
    for (int i = 0; i < len; i++) {
      int it = cpdomains[i].find(' ');
      // printStrA(parse);
      int count = stoi(cpdomains[i].substr(0, it));
      // cout << parse[1] << ": " << count << endl;
      hash[cpdomains[i].substr(it + 1)] += count;
      while ((it = cpdomains[i].find('.', it + 1)) != std::string::npos) {
        hash[cpdomains[i].substr(it + 1)] += count;
      }
    }
    for (auto &[key, val] : hash) {
      ans.emplace_back(std::to_string(val) + " " + key);
    }
    printV(ans, "string mat:");
    return ans;
  }
};

int main() {
  Solution sol;
  vector<string> ex1 = {"900 google.mail.com", "50 yahoo.com",
                        "1 intel.mail.com", "5 wiki.org"};
  sol.subdomainVisits(ex1);
  return 0;
}