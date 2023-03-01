#include <ostream>
#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void count_n(int ind) {
  static vector<int> str = {1, 2, 3};
  str.push_back(ind);
  cout << ind << ": " << str.size() << endl;
}

int main() {
  using namespace std;
  for (auto i : {1, 2, 3, 4}) {
    count_n(i);
  }
  return 0;
  string s1 = "123";
  string s2 = "4";
  std::cout << (s1 < s2) << std::endl;
  s1[0] = '2';
  std::cout << "s1: " << s1 << std::endl;
  cout << "s2: " << s2 << endl;
  int mark = -1;
  cout << "comp: " << (1 == -mark) << endl;
  for (int i = -3; i < 8; i++)
    cout << i << " %5: " << (i % 5) << endl;
  vector<int> arr = {0, 1, 2, 3};
  cout << "arr[-1] " << arr[-1] << endl;
  for (int i = 0; i < 20; i += 3) {
    cout << i << " ^ 1 = " << (i ^ 1) << endl; 
  }
}