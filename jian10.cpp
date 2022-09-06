#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
class Solution {
    long mem[110];
public:
    Solution(){
        for(int i = 0; i < 110; i++){
            mem[i] = 0;
        }
    }
    int fib(int n) {
        if( n == 0)
            return 0;
        if( n == 1)
            return 1;
        if( mem[n] != 0)
            return mem[n];
        mem[n] = (fib(n-1) + fib(n -2))%(int)(1e9+7);
        return mem[n];
    }
};

int main() {
  Solution sol;
  sol.fib(100);
}