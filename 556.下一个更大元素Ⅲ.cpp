#include<iostream>
#include<string>

/* https://leetcode.cn/problems/next-greater-element-iii/

给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。

注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。



示例 1：
    输入：n = 12
    输出：21

示例 2：
    输入：n = 21
    输出：-1

*/

using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        // 转换成字符串
        string nums = to_string(n);
        // 找到第一个递减元素
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        // 
        if (i < 0) {
            return -1;
        }

        // 找到第一个大于nums[i] 的元素
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }


        // 交换两个元素
        swap(nums[i], nums[j]);
        // 翻转i + 1后面的字符串
        reverse(nums.begin() + i + 1, nums.end());

        // 拼接结果
        long ans = stol(nums);
        return ans > INT_MAX ? -1 : ans;
    }
};