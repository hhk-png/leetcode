#include<iostream>
#include<vector>
#include<algorithm>

// https://leetcode.cn/problems/largest-divisible-subset/submissions/
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        // 排序
        sort(nums.begin(), nums.end());

        // dp 数组
        // dp[i] 表示以nums[i] 为最大整数的整除子集的大小
        vector<int> dp(n, 1);
        // 最大整除子集的大小
        int maxSize = 1;
        // 最大整除子集中最大的数
        int maxVal = 0;
        for (int i = 1; i < n; i++) {
            // j 的遍历范围为 0 ~ i - 1
            for (int j = 0; j < i; j++) {
                // 只有较大的数模较小的数的时候才会出现等于0 的情况
                //  如果 nums[j] 能整除 nums[i] 说明nums[i] 可以扩充在以nums[j] 为最大整数的整除子集里成为一个更大的整除子集
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                // 找到了一个更大的整除子集
                if (dp[i] > maxSize) {
                    // 调整maxSize
                    maxSize = dp[i];
                    // 替换maxVal
                    maxVal = nums[i];
                }
            }
        }

        vector<int> res;
        // maxSize 为1， 将nums[0] 作为结果
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }

        // 最大整除子集不一定包括nums 中最大的整数，
        // 在nums 中找出maxSize 个符合要求的元素
        for (int i = n - 1; i >= 0; i--) {
            // 能整除maxVal，
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                // 替换maxVal
                maxVal = nums[i];
                // maxSize 减 1
                maxSize--;
            }
        }
        return res;
    }
};