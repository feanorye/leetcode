#include <iostream>
#include <vector>
#include <string>
using namespace std;
class exam {
  int val;
  public:
  exam(int v):val(v) { cout << "#" << val << "New exam create\n"; }
  ~exam() {
    cout << "#" << val << " exam delete\n";
  }
};
void disp(exam ex) {
  cout << ex.val;
}
int main() {
  using std::move;
  exam e1(1);
  exam e2(2);
  e1 = std::move(e2);
  cout << "done\n";
  e2 = {3};
  return 0;
}