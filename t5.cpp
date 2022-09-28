#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main() {
  using namespace std;
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
}