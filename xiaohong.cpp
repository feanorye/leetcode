#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void maxSubArraySum(vector<int> a, int size, int x) {
  int max_so_far = a[0];
  int curr_max = a[0];
  int start = 0, end = 0, s = 0;

  for (int i = 1; i < size; i++) {
    curr_max = max(a[i], curr_max + a[i]);
    if (curr_max == a[i]) {
      s = i;
    }
    if (max_so_far < curr_max) {
      max_so_far = curr_max;
      start = s;
      end = i;
    }
  }

  int min_num = a[start];
  cout << "sum: " << max_so_far << " " << start << "->" << end << " {";
  for (int i = start; i <= end; i++) {
    min_num = min(a[i], min_num);
    cout << a[i] << ",";
  }
  cout << "}" << endl;

  if (start > 0 || end < size - 1) {
    cout << "change: " << max_so_far + x << endl;
  } else {
    cout << "change: " << max_so_far + max(0, x - min_num) << endl;
  }
}
int main() {
  vector<int> ex5{-5, -3};
  maxSubArraySum(ex5, ex5.size(), 10);
  vector<int> ex4{-5, -2, -1, -6, -3};
  maxSubArraySum(ex4, ex4.size(), 0);
  vector<int> ex3{5, -1, -5, -3, 2};
  maxSubArraySum(ex3, ex3.size(), 0);
  vector<int> ex2{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  maxSubArraySum(ex2, ex2.size(), 0);
  vector<int> ex1{-2, -3, 4, -1, -2, 1, 5, -3};
  maxSubArraySum(ex1, ex1.size(), 0);
}