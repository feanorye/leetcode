#include "listnode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;

class Solution {
public:
  /*
    1. 它由英语小写字母表的前 k 个字母组成。
    2. 它不包含任何长度为 2 或更长的回文子字符串
*/
  string smallestBeautifulString(string s, int k) {
    // 当成k进制
    // 不出现大于2字符的回文串：m个字符回文，必定 m-2个字符回文串
    // 必定不能出现2 or 3的回文串
    // (e.g) dacd -> dada ->dbaa -> dbab -> dbac
    // abcabc -> abcaca ->abcbaa -> abccaa -> acaaaa -> acbaaa
    // -> acbaba -> acbaca -> acbacb
    // 1. 从后往前加
    // 2. 出现回文时需要从前往后进行处理：否则后面节点回文不能解决前面的回文
    // 3. 参数s为美丽字符串，故不存在回文
    int len = s.size();
    k = k + 'a';
    s[len - 1]++;
    for (int i = len - 1; i >= 0 && i < len;) {
      if (s[i] == k) {
        if (i == 0) //越界
          return {""};
        s[i] = 'a';
        s[--i]++; //下个回合判断
      } else if (i > 0 && s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
        // 判断操作是否导致回文，是则增1,跳下一个字典序字符串
        s[i]++;
      } else {
        i++;//不存在回文时，不断向右前进，不断判断右边字符串，直到全部检查成功
      }
    }
    return s;
  }
};

int main() {
  Solution sol;
  return 0;
}