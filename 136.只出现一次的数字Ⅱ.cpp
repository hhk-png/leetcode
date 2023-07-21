#include<iostream>
#include<vector>
using namespace std;

/*
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

示例 1：
	输入：nums = [2,2,3,2]
	输出：3

示例 2：
	输入：nums = [0,1,0,1,0,1,99]
	输出：99

*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// 存储最终结果
		int ans = 0;
		// 遍历二进制的每一个 bit
		for (int i = 0; i < 32; ++i) {
			int total = 0;
			for (int num : nums) {
				// num 向右移动 i 位，然后与 1，表示取出了 num 的第 i 个 bit 的值
				total += ((num >> i) & 1);
			}
			// 答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数
			// total % 3 不为 0， 表示数组中的唯一元素在此位置上有值
			if (total % 3) {
				// 将 1 向左移动 i 位后，与 ans 或，将该位置上的 1 拷贝到 ans 上
				ans |= (1 << i);
			}
		}

		return ans;
	}
};