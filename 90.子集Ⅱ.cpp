#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 
示例 1：
	输入：nums = [1,2,2]
	输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
	输入：nums = [0]
	输出：[[],[0]]

*/

class Solution {
public:
	vector<int> temp;
	vector<vector<int>> ans;

	void dfs(vector<int>& nums, int index) {
		ans.push_back(temp);
		for (int i = index; i < nums.size(); ++i) {
			// 为了保证最终结果中不包含重复元素，
			//	只要在遇到 nums 中的重复元素时，保证 dfs 的次数为 1 即可
			if (i > index && nums[i] == nums[i - 1]) {
				// 当第一次遇到重复元素时，才会不进入 if 判断
				continue;
			}
			temp.push_back(nums[i]);
			dfs(nums, i + 1);
			temp.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		// 先排序
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}
};

