#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/coin-change-ii/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        // coins 要放在外层，否则会造成结果的重复
        for (int& coin : coins) {
            // i 从coin 开始
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};