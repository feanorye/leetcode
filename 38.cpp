#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    string countAndSay(int n) {
        string result, ans, prefix;
        char tmp = 0;
        int count = 0;
        if( n == 1){
            return "1";
        }
        result = countAndSay(n-1);
        tmp = result[0];
        for(auto k : result){
            if( k == tmp )
                count++;
            else{
                prefix = "0";
                prefix[0] += count;
                ans = ans + prefix + tmp;
                //初始化
                tmp = k;
                count = 1;
            }
        }
            prefix = "0";
            prefix[0] += count;
            ans = ans + prefix + tmp;
        return ans;
    }
};

int main(){
    Solution sol;
    string s = sol.countAndSay(4);
    cout << s << endl;
    return 0;
}