#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/predict-the-winner/submissions/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // ������յ�ֵ����0��˵�����1 �ķ�����
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }

    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);

        // ���ؾ���ֵ�����
        if (turn == 1) {
            return max(scoreStart, scoreEnd);
        }
        else {
            return min(scoreStart, scoreEnd);
        }
    }
};

class Solution2 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
