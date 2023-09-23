#include "include/quick_sort.h"
#include <corecrt.h>
#include <iostream>
#include<stdio.h>

template <typename T> void printv(T arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    auto v = arr[i];
    std::cout << v << ", ";
  }
  std::cout << std::endl;
}
int f(unsigned int n) {
  n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
  n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
  n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
  n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
  n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
  return n;
}
int main() {
  using namespace sort;
  int arr[] = {12, 4, 5, 2, 1, 8, 22, 55, 43, 23};
  quickSort(arr, 0, 9);
  printv<int>(arr, sizeof(arr) / sizeof(arr[0]));
  printf("ans == %ld\n", f(197));
}