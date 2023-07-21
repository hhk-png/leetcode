#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/frog-jump/submissions/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][k] 表示青蛙能否达到[现在所处的石子编号]为i 且[上一次跳跃距离]为k 的状态
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; i++) {
            // 当青蛙达到第i - 1 个石子时，他的[上一次跳跃距离]至多为 i - 1 因此在第i 个石子上最远只能跳出i 的距离
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // 从j 到i 需要跳跃的距离为 k
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                // 当在j 位置时跳跃距离至少为k - 1 才能跳跃到i
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                // 最后一个位置
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }

        return false;
    }
};

