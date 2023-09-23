#include <iostream>
#include "heap_sort.h"
void print(int nums[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << ",";
  }
}
int main() {
  std::vector<int> nums = {4, 12, 32, 11, 56, 3, 1, 45};
  my_sort::heap h1{nums};
  h1.ToString();
}