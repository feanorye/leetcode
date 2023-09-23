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

using std::cin;
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

void anxiety() {
  vector<int> work, podcast;
  int n, x, y;
  std::cin >> n >> x >> y;
  int data;
  for (int i = 0; i < n; i++) {
    cin >> data;
    work.push_back(data);
  }
  for (int i = 0; i < n; i++) {
    cin >> data;
    podcast.push_back(data);
  }
  int emotion = 0;
  for (int i = 0; i < n; i++) {
    emotion += work[i] * x - podcast[i] * y;
    emotion = max(0, emotion);
  }
  cout << emotion;
}
int main() {
  anxiety();
  return 0;
}