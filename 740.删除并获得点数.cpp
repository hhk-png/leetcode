#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/delete-and-earn/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            // ����first ��second �ĵ���
            int temp = second;
            // first + nums[i]: ɾ����ǰ����
            //  second: ��ɾ����ǰ����
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        vector<int> sum(maxVal + 1);
        for (int num : nums) {
            sum[num] += num;
        }

        return rob(sum);
    }
};

