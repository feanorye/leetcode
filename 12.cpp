#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;
const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};
class Solution {
public:
    string intToRoman(int num) {
        string ans;
        char sym[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int div = 1000;
        int res = 0;
        int tmp;
        int level = 0;
        //确定位数
        if( num / 1000 != 0 ) level = 3;
        else if( num / 100 != 0 ) level = 2;
        else if( num / 10 != 0 ) level = 1;
        else level = 0;
        div = std::pow(10, level);
        for(;num != 0;){
            tmp = num / div;
            num = num % div;
            if( tmp == 9 || tmp == 4 ){
                ans += sym[level * 2];
                ans += sym[level * 2 + tmp / 5 + 1];
            }else{
                if( tmp >= 5 ){ // 注意58
                    ans += sym[level * 2 + 1];
                    tmp -= 5;
                }
                for(int i = 0; i < tmp; i++){
                    ans += sym[level * 2];
                }
            }
            level--;
            div = div / 10;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    cout << sol.intToRoman(942) << endl;
    for(auto &[k, v]: valueSymbols){
        cout << "val: " << k << " \t" <<  v << endl;
    }
}