#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

示例 1：
	输入：nums = [1,2,3,1], k = 3
	输出：true

示例 2：
	输入：nums = [1,0,1,1], k = 1
	输出：true

示例 3：
	输入：nums = [1,2,3,1,2,3], k = 2
	输出：false

*/

/*
	hash
*/
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		// val -> index
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			// map 中存在 num ，并且与上一个 num 之间的距离小于等于 k
			if (map.count(num) && (i - map[num] <= k)) {
				return true;
			}
			// 将 num 放入 map 中，或者说替换原来的 num 的坐标，
			//	将其更新为最新的坐标，供下一次判断使用，
			map[num] = i;
		}

		return false;
	}
};


/*
	滑动窗口
*/
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> set;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			// 维持一个固定大小的滑动窗口，长度为 k + 1
			if (i > k) { // i > k 时需要删除窗口最前面的那个元素
				// 删除元素之后，窗口的大小为 k - 1
				set.erase(nums[i - k - 1]);
			}
			// 在窗口内存在两个相同的元素
			if (set.count(nums[i])) {
				return true;
			}
			// 将当前元素放入窗口中
			set.emplace(nums[i]);
		}

		return false
	}
};


