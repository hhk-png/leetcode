#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        // 状态 dp[i][d] 表示尾项为 nums[i]，公差为 d 的弱等差子序列的个数。
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - nums[j];
                auto it = dp[j].find(d);
                int cnt = it == dp[j].end() ? 0 : it->second;
                result += cnt;
                dp[i][d] += cnt + 1;
            }
        }
        return result;
    }
};

