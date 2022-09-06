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
    private:
        int m, n;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        int tmp = 0;
        vector<vector<int>> right, down;
        right.resize(m, vector<int>(n, 0));
        down.resize(m, vector<int>(n, 0));
        findDown(matrix, down);
        findRight(matrix, right);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(down[i][j] != 0){
                    //tmp = 1;
                    int len = min(down[i][j], right[i][j]);
                    for(int k = 1; k < len; k++){
                        len = min(down[i][j + k], len);
                    }
                    tmp = len;
                }
                ans = max(ans, tmp);
            }
        }

        return ans * ans;

    }
    int findRight(vector<vector<char>>& matrix, vector<vector<int>>& right){
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(count != 0){
                    right[i][j] = count--;
                    continue;
                }
                if( matrix[i][j] == '1' ){
                    int k = j;
                    for(;k < n;k++){
                        if( matrix[i][j] == '1' )
                            count++;
                        else
                            break;
                    }
                    right[i][j] = count--;
                }
            }

        }
        return 0;
    }
    int findDown(vector<vector<char>>& matrix, vector<vector<int>>& down){
        int count = 0;

        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(count != 0){
                    down[i][j] = count--;
                    continue;
                }
                if( matrix[i][j] == '1' ){
                    int k = i;
                    for(;k < m;k++){
                        if( matrix[k][j] == '1' )
                            count++;
                        else
                            break;
                    }
                    down[i][j] = count--;
                }
            }

        }
        return 0;
    }
    int maximalSquare2(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> right(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    right[i][j] = matrix[i][j] - '0';
                }else if(matrix[i][j] == '0'){
                    right[i][j] = 0;
                }else{
                    right[i][j] = min(min(right[i-1][j], right[i-1][j-1]), right[i][j-1]) + 1;
                }
                ans = max(ans, right[i][j]);
            }
        }
        return ans * ans;

    }
};
int main(){
    using namespace std;
    Solution sol;
    vector<vector<char>> mat =
        {{'1', '0', '1', '0', '0'},
         {'1', '0', '1', '1', '1'},
         {'1', '1', '1', '1', '1'},
         {'1', '0', '0', '1', '0'}};
    int ans = sol.maximalSquare2(mat);
    cout << ans << endl;
    cout << min(12, 3);
    return 0;
}