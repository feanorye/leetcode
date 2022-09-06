#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
class Solution
{
private:
    vector<vector<bool>> dp;

public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));//因为包含了空字串的情况
        //初始化 
        dp[0][0] = true;//两个空字串
        for (int j = 2;j < lenp + 1;j++)//找出s为空 但p因为* 为空的情况(e.g: a*a*a*)
        {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        //更新
        for (int i = 1;i < lens + 1;i++) {
            for (int j = 1;j < lenp + 1;j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')//情况1：符合，直接更新
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')//情况2：考虑*的情况
                {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];//分别是  重复0次；重复一次；重复两次及以上！！！
                    }
                    else//s[i-1] p[j-2]不匹配  *需要重复0次
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
/*     bool isMatch11(string s, string p)
    {
        int nums = s.size();
        int nump = p.size();
        dp.resize(nums, vector<int>(nump, false));
        return helper(s, p);
    } */
    bool helper(string s, string p)
    {
        int is = s.size() - 1;
        int ip = p.size() - 1;
    }
    bool isMatch2(string s, string p)
    {
        int is = 0, ip = 0;
        int nums = s.size();
        int nump = p.size();
        for (; is < nums && ip < nump;) {
            if (p[ip] == '.') {
                ip++;
                is++;
            }
            else {
                if (p[ip] == '*') { // >= 0
                    if ((nump - ip) <= (nums - is)) {
                        is++;
                    }
                    else {
                        ip++;
                        // is++;
                    }
                }
                else {
                    if (p[ip] == s[is]) {
                        ip++;
                        is++;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if (is != nums || ip != nump)
            return false;
        return true;
    }
};
int main()
{
    Solution sol;
    cout << "test#1" << sol.isMatch(string("aa"), string("a*a")) << endl;
    cout << "test#2" << sol.isMatch(string("aabab"), string("a*a.")) << endl;
    cout << "test#2" << sol.isMatch(string("mississippi"), string("mis*is*p*.")) << endl;
}