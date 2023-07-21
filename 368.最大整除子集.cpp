#include<iostream>
#include<vector>
#include<algorithm>

// https://leetcode.cn/problems/largest-divisible-subset/submissions/
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        // ����
        sort(nums.begin(), nums.end());

        // dp ����
        // dp[i] ��ʾ��nums[i] Ϊ��������������Ӽ��Ĵ�С
        vector<int> dp(n, 1);
        // ��������Ӽ��Ĵ�С
        int maxSize = 1;
        // ��������Ӽ���������
        int maxVal = 0;
        for (int i = 1; i < n; i++) {
            // j �ı�����ΧΪ 0 ~ i - 1
            for (int j = 0; j < i; j++) {
                // ֻ�нϴ����ģ��С������ʱ��Ż���ֵ���0 �����
                //  ��� nums[j] ������ nums[i] ˵��nums[i] ������������nums[j] Ϊ��������������Ӽ����Ϊһ������������Ӽ�
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                // �ҵ���һ������������Ӽ�
                if (dp[i] > maxSize) {
                    // ����maxSize
                    maxSize = dp[i];
                    // �滻maxVal
                    maxVal = nums[i];
                }
            }
        }

        vector<int> res;
        // maxSize Ϊ1�� ��nums[0] ��Ϊ���
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }

        // ��������Ӽ���һ������nums ������������
        // ��nums ���ҳ�maxSize ������Ҫ���Ԫ��
        for (int i = n - 1; i >= 0; i--) {
            // ������maxVal��
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                // �滻maxVal
                maxVal = nums[i];
                // maxSize �� 1
                maxSize--;
            }
        }
        return res;
    }
};