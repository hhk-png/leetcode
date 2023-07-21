#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/coin-change-ii/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        // coins Ҫ������㣬�������ɽ�����ظ�
        for (int& coin : coins) {
            // i ��coin ��ʼ
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};