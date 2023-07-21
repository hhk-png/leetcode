#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// https://leetcode.cn/problems/can-i-win/submissions/

class Solution {
public:
    unordered_map<int, bool> memo;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // 不构成输赢的条件
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }
    bool dfs(int maxChoosableInteger, int usedNum, int desiredTotal, int currentTotal) {
        // 记录中已经存在该组选中值，就不需要再进行选数流程
        if (!memo.count(usedNum)) {
            // 最终结果
            bool res = false;
            // 挨个选
            for (int i = 0; i < maxChoosableInteger; i++) {
                // 该数没有被选中
                if (((usedNum >> i) & 1) == 0) {
                    // 获胜了
                    if (i + 1 + currentTotal >= desiredTotal) {
                        res = true;
                        break;
                    }
                    // 对手输了
                    if (!dfs(maxChoosableInteger, usedNum | (1 << i), desiredTotal, i + 1 + currentTotal)) {
                        res = true;
                        break;
                    }
                }
            }
            // 流程结束后再保存值
            memo[usedNum] = res;
        }
        return memo[usedNum];
    }
};



