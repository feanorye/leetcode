#pragma once

namespace my_sort {
template <typename T> void swap(T *a, T *b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}
// @return: piviot postion
template <typename T> int partion(T arr[], int low, int high) {
  int i = low - 1; // i always point to smaller rightmost pos.
  for (int j = low; j < high; j++) {
    if (arr[j] < arr[high]) {
      i++; // i point to higher postion now
      swap(&arr[i], &arr[j]); // i point to smaller right most pos again.
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}
template <typename T> void quickSort(T arr[], int low, int high) {
  if (low < high) {
    int pivot = partion(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}
} // namespace my_sort