#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
using std::string;
using std::vector;

class SnapshotArray {
private:
  int snap_id;
  vector<map<int,int>> arr;
public:
    SnapshotArray(int length):arr(length,map<int,int>()),snap_id(0) {
      for (int i = 0; i < length; i++)
        arr[i][snap_id] = 0;
    }
    
    void set(int index, int val) {
      arr[index][snap_id] = val;
    }
    
    int snap() {
      snap_id++;
      return snap_id-1;
    }

    int get(int index, int snap_id) {
      auto it = arr[index].upper_bound(snap_id);
      it--;
      return arr[index][it->first];
    }
};

int main() {
  SnapshotArray sol(2);
  vector<vector<char>> ex1;
  return 0;
}