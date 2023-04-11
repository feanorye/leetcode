#include "listnode.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <tuple>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::vector;
using std::get;

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // 四种事件：需要耗时完成
        // ReachRight - 有工人到达右岸，开始拿旧仓库的箱子
        // GoLeft - 有工人拿完了旧仓库的箱子，等待回左岸： 特殊，需要排队
        // ReachLeft - 有工人到达了左岸，开始放新仓库的箱子
        // Complete - 有工人完成搬运，返回河左岸等待下一个任务：特殊，需要排队
        const int ReachRight = 0, GoLeft = 1, ReachLeft = 2, Complete = 3;
        
        // 时间-事件序列 <时间，事件类型，工人下标>： 注意goleft在前，隐藏顺序右边队列> 左边队列
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q_event;
        
        // 左岸工人 <耗时，下标>： 优先耗时长的工人
        priority_queue<pair<int,int>> q_left;
        
        // 右岸工人 <耗时，下标>
        priority_queue<pair<int,int>> q_right;
        
        // 初始化，工人都在左岸
        for(int i = 0; i < k; ++i) 
            q_left.push({time[i][0] + time[i][2], i});
        
        // t - 当前时间: q_event会保存真正的时间
        // bridgecnt - 当前桥上的人数
        // needcnt - 尚需搬运的箱子数
        // returncnt - 返回左岸的箱子数
        int t = 0, bridgecnt = 0, needcnt = n, returncnt = 0, res = 0;
        while(returncnt < n) {
            // 如果桥上没人，那么安排人过桥：只安排一个人
            if(bridgecnt == 0) {
                // 优先安排右岸
                if(q_right.size()) {
                    auto [unused, idx] = q_right.top(); q_right.pop();
                    q_event.push({t + time[idx][2], ReachLeft, idx});
                    bridgecnt = 1;
                } 
                // 右岸没人，安排左岸
                else if(q_left.size()) {
                    // 只有还有需要搬运的箱子时，才安排
                    if(needcnt) {
                        auto [unused, idx] = q_left.top(); q_left.pop();
                        q_event.push({t + time[idx][0], ReachRight, idx});
                        needcnt--;
                        bridgecnt = 1;
                    }
                }
            }

            // 等待下个事件到来
            if(q_event.size()) {
                // t -> 下个事件发生的时间；用while处理完所有同时发生的事件
                // t: 事件队列中保存真正的时间  
                t = -1;
                while(q_event.size() && (t == -1 || get<0>(q_event.top()) == t)) {
                    auto [end_t, type, idx] = q_event.top(); q_event.pop();
                    t = end_t;
                    if(type == ReachRight) { // 有工人到达右岸，开始拿旧仓库的箱子
                        q_event.push({t + time[idx][1], GoLeft, idx});
                        bridgecnt = 0;
                    } else if (type == GoLeft) {
                      // 有工人拿完了旧仓库的箱子，等待回左岸：需要排队，不进事件队列
                        q_right.push({time[idx][0] + time[idx][2], idx});
                    } else if(type == ReachLeft) { // 有工人到达了左岸，开始放新仓库的箱子
                        q_event.push({t + time[idx][3], Complete, idx});
                        returncnt++;
                        res = t;
                        bridgecnt = 0;
                    } else { // 有工人完成搬运，返回河左岸等待下一个任务： 排队，不进事件队列
                        q_left.push({time[idx][0] + time[idx][2], idx});
                    }
                }
            }
        }
        
        return res;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> ex1 = { {1, 9, 1, 8}, {10, 10, 10, 10}};
  printInt("ans: 50 -- ", sol.findCrossingTime(3, 2, ex1));
  return 0;
}