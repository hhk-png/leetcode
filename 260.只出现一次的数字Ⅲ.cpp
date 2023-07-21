#include<iostream>
#include<vector>
using namespace std;

/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
	找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？


示例 1：
	输入：nums = [1,2,1,3,2,5]
	输出：[3,5]
	解释：[5, 3] 也是有效的答案。

示例 2：
	输入：nums = [-1,0]
	输出：[-1,0]

示例 3：	
	输入：nums = [0,1]
	输出：[1,0]
*/

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		// xorsum 的最终结果是 a ^ b
		int xorsum = 0;
		for (int num : nums) {
			xorsum ^= num;
		}

		// 取出 xorsum 最低位的 1
		//	那么 a 和 b 中的某一个数二进制第 l 位为0，另一个为 1，这种情况下, a ^ b的二进制表示的第l位才能为1
		int lsb = xorsum == INT_MIN ? xorsum : xorsum & (-xorsum);
		// 我们通过第 l 位是否为1，把 nums 中的元素分为两类，
		//  那么 a b 分别在这两个集合内，通过异或运算将 a b 取出
		int type1 = 0,
			type2 = 0;
		for (int num : nums) {
			if (num & lsb) {
				type1 ^= num;
			}
			else {
				type2 ^= num;
			}
		}
		return { type1 , type2 };
	}
};
