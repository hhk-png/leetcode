#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        // ��¼������dp �����е�����
        vector<long> pointers(m, 0);
        vector<long> nums(m, 1);
        vector<long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // ��ȡnums �е���Сֵ
            long minNum = LONG_MAX;
            for (int i = 0; i < m; i++) {
                minNum = min(minNum, nums[i]);
            }
            // ��Ϊdp[i]
            dp[i] = minNum;
            // ����һ�ε� nums[i]
            for (int i = 0; i < m; i++) {
                // ������ͬ������˵�������Ѿ���dp �г��ֹ���
                if (minNum == nums[i]) {
                    // ָ����ǰ�� 1�����¼��� nums[i]
                    pointers[i]++;
                    nums[i] = dp[pointers[i]] * primes[i];
                }
            }
        }
        return dp[n];
    }
};