#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/frog-jump/submissions/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][k] ��ʾ�����ܷ�ﵽ[����������ʯ�ӱ��]Ϊi ��[��һ����Ծ����]Ϊk ��״̬
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; i++) {
            // �����ܴﵽ��i - 1 ��ʯ��ʱ������[��һ����Ծ����]����Ϊ i - 1 ����ڵ�i ��ʯ������Զֻ������i �ľ���
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // ��j ��i ��Ҫ��Ծ�ľ���Ϊ k
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                // ����j λ��ʱ��Ծ��������Ϊk - 1 ������Ծ��i
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                // ���һ��λ��
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }

        return false;
    }
};

