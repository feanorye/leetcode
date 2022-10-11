#include <iostream>
int main() {
  using std::cout;
  using std::endl;
  cout << "hello,world" << endl;
  int left = 1, right = 1;
  for (; right < 20; right++) {
    int m1 = left + (right - left) / 2;
    int m2 = left + (right - left + 1) / 2;
    double m3 = (double)(left + right) / 2;
    cout << left << " " << right << " : " << m1 << " : " << m2 << ": " << m3
         << endl;
  }
  cout << "NULL: " << (0 == NULL) << endl;
  cout << "nullptr: " << (0 == nullptr) << endl;
  //快慢指针小型测试：非正式，正式可参考初等数论
  int fast = 1, slow = -3;
  int r = 0;
  while (1) {
    if (fast == slow) {
      cout << "round " << r++ << endl;
    }
    if (r == 2)
      break;
    fast = (fast + 2) % 9;
    slow = (slow + 1) % 9;
    cout << slow << " " << fast << endl;
  }
  cout << "e4: " << 10e4 << endl;
  return 0;
}