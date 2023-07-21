#include<iostream>
#include<vector>
using namespace std;

/*
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

 
示例 1：
	输入：numbers = [2,7,11,15], target = 9
	输出：[1,2]
	解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

示例 2：
	输入：numbers = [2,3,4], target = 6
	输出：[1,3]
	解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。

示例 3：
	输入：numbers = [-1,0], target = -1
	输出：[1,2]
	解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

*/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right) {
			int ans = numbers[left] + numbers[right];
			if (ans == target) {
				return { left + 1, right + 1 };
			} else if (ans < target) {
				left++;
			} else {
				right--;
			}
		}

		return { -1, 1 };
	}
};


class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0; i < numbers.size(); ++i) {
			// 为了避免重复寻找，在寻找第二个数时，只在第一个数的右侧寻找
			/*
				输入：
					[1,2,3,4,4,9,56,90]
					8
				输出：
					[4,4]
				预期结果：
					[4,5]
			*/
			int low = i + 1, 
				high = numbers.size() - 1;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (numbers[i] + numbers[mid] == target) {
					return { i + 1, mid + 1 };
				} else if (numbers[i] + numbers[mid] < target) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
		}

		return { -1, 1 };
	}
};


