#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // dp[i][j] ��ʾ�������ǰi �����ָ�Ϊj �����ܵõ�������������������Сֵ
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        dp[0][0] = 0;
        // ǰi ����
        for (int i = 1; i <= n; i++) {
            // ��ǰi ������Ϊj ��
            for (int j = 1; j <= min(n, m); j++) {
                // �� [0, k] ��Χ�ڵ�����Ϊj - 1 �ݣ��� [k + 1, i] ��Χ�ڵ�����Ϊһ��
                //  ���һ�ݵ�������ĳ�����СΪ 1
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
                }
            }
        }

        return (int)dp[n][m];
    }
};
