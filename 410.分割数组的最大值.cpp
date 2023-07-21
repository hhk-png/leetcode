#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // dp[i][j] 表示将数组的前i 个数分割为j 段所能得到的最大连续子数组的最小值
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        dp[0][0] = 0;
        // 前i 个数
        for (int i = 1; i <= n; i++) {
            // 将前i 个数分为j 份
            for (int j = 1; j <= min(n, m); j++) {
                // 将 [0, k] 范围内的数分为j - 1 份，将 [k + 1, i] 范围内的数作为一份
                //  最后一份的子数组的长度最小为 1
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
                }
            }
        }

        return (int)dp[n][m];
    }
};
