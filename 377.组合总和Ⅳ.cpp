#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/combination-sum-iv/submissions/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        // dp[i] 和为i 的组合的个数
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
