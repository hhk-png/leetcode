#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/integer-break/submissions/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);

        for (int i = 2; i < n + 1; i++) {
            int curMax = 0;
            // 从1 开始拆分，一直到 i - 1
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }

        return dp[n];
    }
};