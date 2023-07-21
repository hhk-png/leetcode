#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// https://leetcode.cn/problems/can-i-win/submissions/

class Solution {
public:
    unordered_map<int, bool> memo;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // ��������Ӯ������
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }
    bool dfs(int maxChoosableInteger, int usedNum, int desiredTotal, int currentTotal) {
        // ��¼���Ѿ����ڸ���ѡ��ֵ���Ͳ���Ҫ�ٽ���ѡ������
        if (!memo.count(usedNum)) {
            // ���ս��
            bool res = false;
            // ����ѡ
            for (int i = 0; i < maxChoosableInteger; i++) {
                // ����û�б�ѡ��
                if (((usedNum >> i) & 1) == 0) {
                    // ��ʤ��
                    if (i + 1 + currentTotal >= desiredTotal) {
                        res = true;
                        break;
                    }
                    // ��������
                    if (!dfs(maxChoosableInteger, usedNum | (1 << i), desiredTotal, i + 1 + currentTotal)) {
                        res = true;
                        break;
                    }
                }
            }
            // ���̽������ٱ���ֵ
            memo[usedNum] = res;
        }
        return memo[usedNum];
    }
};



