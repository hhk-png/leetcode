#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        // 记录的是在dp 数组中的索引
        vector<long> pointers(m, 0);
        vector<long> nums(m, 1);
        vector<long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // 获取nums 中的最小值
            long minNum = LONG_MAX;
            for (int i = 0; i < m; i++) {
                minNum = min(minNum, nums[i]);
            }
            // 作为dp[i]
            dp[i] = minNum;
            // 求下一次的 nums[i]
            for (int i = 0; i < m; i++) {
                // 遇到相同的数，说明此数已经在dp 中出现过了
                if (minNum == nums[i]) {
                    // 指针向前加 1，重新计算 nums[i]
                    pointers[i]++;
                    nums[i] = dp[pointers[i]] * primes[i];
                }
            }
        }
        return dp[n];
    }
};