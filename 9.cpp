#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
using std::cout;
using std::endl;
using std::vector;
class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;

        long long y = 0, rem = 0;
        int xb = x;

        for(; x != 0;){
            rem = x % 10;
            y = (long long)(y * 10 + rem);
            x = x / 10;
        }
        return xb == y;
    }
};
int main(){
    Solution sol;
    cout << sol.isPalindrome(1234567899);
}