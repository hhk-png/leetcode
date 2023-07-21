#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/guess-number-higher-or-lower-ii

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // dp[i][j] ��ʾ [i, j] ��Χ���������С�����
        // ǰ����ѭ����������ķ�Χ
        // �Խ����ϵ�Ԫ�ز����м���
        // [n - 1, 1]
        for (int i = n - 1; i >= 1; i--) {
            // [i + 1, n]
            for (int j = i + 1; j <= n; j++) {
                // j Ϊ�ұ߽�
                dp[i][j] = j + dp[i][j - 1];
                // [i, j - 1]
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }

        return dp[1][n];
    }
};