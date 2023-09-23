#pragma once
#include <iostream>
#include <vcruntime.h>
#include <vector>
// 堆排序
namespace my_sort {
class heap {
private:
  std::vector<int> arr_;

public:
  /**
   * 0: 2^0 = 1     0
   * 1: 2^1 = 2  {1,    2}
   * 2: 2^2 = 4 {3, 4, 5, 6}
   * k: 2^k   {2^k-1, 2^k, ...}
   * k+1:   {2^(k+1)-1, 2^{k+1}, ...}
   * 类似二进制：0111 = 2^3-1, 01111 = 2^4-1
   *
   * 观察k和k+1层：2*(2^k-1)+1 = 2^(k+1)-1, 2*{2^k-1}+2 = 2^(k+1)
   * 令m = 2^k-1，则lchild = 2m+1, 2m+2
   * 再m右移一位，新的父节点为m+1，
   * lchild = 2m+2+1 = 2(m+1)+1,
   * rchild = 2(m+1)+2
   * 故，已知child = {2m+1, 2m+2}, 父节点为 floor((child.index - 1)/2)
   */
  heap(std::vector<int> &arr) : arr_(arr) { HeapSort(); }

  /** 将元素插入到末尾，然后检查和父节点的关系并进行修复  */
  void Insert(int val) {
    arr_.push_back(val);
    int idxc = arr_.size() - 1;
    int idxp = (idxc - 1) / 2;
    while (idxp >= 0 && arr_[idxc] > arr_[idxp]) {
      // 只将父节点下移,到最后确定位置时，在对child进行赋值
      arr_[idxc] = arr_[idxp];
      idxc = idxp;
      idxp = (idxc - 1) / 2;
    }
    arr_[idxc] = val;
  }

  /** 下滤操作：将末尾元素移至头部，然后从上到下进行修复  */
  int remove() {
    int ret = arr_[0];
    int val = arr_.back();
    arr_.pop_back();
    int len = arr_.size();
    int idxp = 0;
    int idxc;
    while (idxp != (idxc = ProperParent(idxp, val, len))) {
      arr_[idxp] = arr_[idxc];
      idxp = idxc;
    }
    arr_[idxp] = val;
    return ret;
  }

  /** 返回当前idxp节点和子节点之间的最大值的索引  */
  int ProperParent(int idxp, int val, int len) {
    int idxc = idxp * 2 + 1;
    if (idxc + 1 < len) {
      if (arr_[idxc] < arr_[idxc + 1]) {
        idxc++;
      }
    }
    if (idxc < len) {
      if (val < arr_[idxc]) {
        return idxc;
      }
    }
    return idxp;
  }
  int ToString() {
    for (auto e : arr_) {
      std::cout << e << ",";
    }
    std::cout << "\b\n";
    return arr_.size();
  }

  void MaxHeapfy(int start, int end) {
    int parent = start;
    int child = parent * 2 + 1; // left child
    while (child < end) {
      if (child + 1 < end && arr_[child] < arr_[child + 1]) {
        child++;
      }
      if (arr_[parent] >= arr_[child]) {
        return;
      } else {
        std::swap(arr_[parent], arr_[child]);
        parent = child;
        child = parent * 2 + 1;
      }
    }
  }
  
  // 堆排序：利用堆特性，不断取最大值，放入右侧已排序区域，直到全部排序成功
  void HeapSort() {
    int len = arr_.size();
    // 从最后一个父节点开始,反向依次检查堆特性：父节点必大于子节点
    for (int i = len / 2 - 1; i >= 0; i--) {
      MaxHeapfy(i, len);
    }
    for (int i = len - 1; i >= 0; i--) {
      std::swap(arr_[0], arr_[i]);
      MaxHeapfy(0, i);
    }
  }
};

} // namespace my_sort