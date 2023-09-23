#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
int main() {
  float a = 1.0000234;
  
  cout << std::setprecision(8) << "float:" << a << endl;
  int x = 0;
  std::string s{""};
  cin.unsetf(std::ios::hex);
  cin.unsetf(std::ios::dec);
  cin.unsetf(std::ios::oct);
  cin >> x >> s;
  cout << "int: " << x << " str: " << s << endl;
}