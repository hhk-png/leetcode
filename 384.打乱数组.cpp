#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。

实现 Solution class:
	Solution(int[] nums) 使用整数数组 nums 初始化对象
	int[] reset() 重设数组到它的初始状态并返回
	int[] shuffle() 返回数组随机打乱后的结果
 

示例 1：

	输入
		["Solution", "shuffle", "reset", "shuffle"]
		[[[1, 2, 3]], [], [], []]
	输出
		[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

	解释
		Solution solution = new Solution([1, 2, 3]);
		solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
		solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
		solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]

*/

class Solution {
public:
	Solution(vector<int>& nums) {
		this->nums = nums;
		this->original.resize(nums.size());
		copy(nums.begin(), nums.end(), original.begin());
	}

	vector<int> reset() {
		copy(original.begin(), original.end(), nums.begin());
		return nums;
	}

	vector<int> shuffle() {
		for (int i = 0; i < nums.size(); ++i) {
			// 类似于插入排序
			//	[0, i] 是已经打乱完顺序的部分数组
			//  [i + 1, n - 1] 是等待抽取出去的数组
			// 从 [i + 1, n - 1] 中抽取元素放到前面
			int j = i + rand() % (nums.size() - i);
			swap(nums[i], nums[j]);
		}
		return nums;
	}
private:
	vector<int> nums;
	vector<int> original;
};

