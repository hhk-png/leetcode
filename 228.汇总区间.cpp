#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
 

示例 1：
	输入：nums = [0,1,2,4,5,7]
	输出：["0->2","4->5","7"]
	解释：区间范围是：
	[0,2] --> "0->2"
	[4,5] --> "4->5"
	[7,7] --> "7"

示例 2：
	输入：nums = [0,2,3,4,6,8,9]
	输出：["0","2->4","6","8->9"]
	解释：区间范围是：
	[0,0] --> "0"
	[2,4] --> "2->4"
	[6,6] --> "6"
	[8,9] --> "8->9"
*/

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int n = nums.size();
		// 存储连续数字串开始的位置
		int left = 0;
		vector<string> res;
		for (int i = 0; i < n; ++i) {
			// 到达了最后一个元素，或者不满足条件
			//	i 表示连续数字串的最后一个位置
			if (i + 1 == n || nums[i] + 1 != nums[i + 1]) {
				res.push_back(to_string(nums[left]) 
					+ (left == i 
						? "" 
						: "->" + to_string(nums[i])));
				left = i + 1;
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int i = 0;
		int n = nums.size();
		vector<string> res;
		
		while (i < n) {
			// 沿着连续数字串前进，标记第一个和最后一个位置
			int low = i;
			i++;
			while (i < n && nums[i] == nums[i - 1] + 1) {
				i++;
			}
			int high = i - 1;

			string temp = to_string(nums[low]);
			// 根据 low 和 high 的大小来判断是否插入后面的字符串
			if (low < high) {
				temp.push_back("->");
				temp.push_back(to_string(nums[high]));
			}
			res.push_back(move(temp));
		}

		return res;
	}
};
