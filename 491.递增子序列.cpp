#include<iostream>
#include<vector>

using namespace std;

/* https://leetcode.cn/problems/increasing-subsequences/

给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。


示例 1：
    输入：nums = [4,6,7,7]
    输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

示例 2：
    输入：nums = [4,4,3,2,1]
    输出：[[4,4]]

*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void dfs(int index, int last, vector<int>& nums) {
        if (index == nums.size()) {
            if (temp.size() >= 2) {
                result.push_back(temp);
            }
            return;
        }

        if (nums[index] >= last) {
            temp.push_back(nums[index]);
            dfs(index + 1, nums[index], nums);
            temp.pop_back();
        }
        // 每次dfs 都会走着一条判断，都会忽略当前位置的数字。
        //      设置不等于判断是为了在遇到连续相等的数字时,
        //      是为了去除result 中重复的元素
        //      和忽略掉当前位置的数字
        if (nums[index] != last) {
            dfs(index + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return result;
    }
};