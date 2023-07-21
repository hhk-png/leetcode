#include<iostream>
#include<vector>

using namespace std;

/* https://leetcode.cn/problems/find-all-duplicates-in-an-array/

给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

 
示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[2,3]
示例 2：

输入：nums = [1,1,2]
输出：[1]
示例 3：

输入：nums = [1]
输出：[]

*/

class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        // 排序，最终非重复数字一定会满足 nums[i] - 1 != i
        //      不满足的则说明是重复的数字
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:

    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            } else { // 如果nums[i] 的值为负数，说明nums[i] 出现了两次
                result.push_back(x);
            }
        }

        return result;
    }
};