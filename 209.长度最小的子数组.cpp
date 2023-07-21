#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：
	输入：target = 7, nums = [2,3,1,2,4,3]
	输出：2
	解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
	输入：target = 4, nums = [1,4,4]
	输出：1

示例 3：
	输入：target = 11, nums = [1,1,1,1,1,1,1,1]
	输出：0

*/

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		// 数组长度
		int n = nums.size();
		// 数组长度为0
		if (n == 0) {
			return 0;
		}
		// 存储最终结果
		int ans = INT_MAX;
		// 前缀和
		vector<int> sum(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			// sum[i]: 数组的前 i 项和
			sum[i] = sum[i - 1] + nums[i - 1];
		}
		for (int i = 1; i <= n; ++i) {
			// 前 i - 1 项和加上 s
			int target = s + sum[i - 1];
			// 如果在 sum 中能找到对应的值
			auto bound = lower_bound(sum.begin(), sum.end(), target);
			if (bound != sum.end()) {
				// 最终等于 s 的连续子数组的长度
				//  (i - 1)：本次循环的起始位置
				ans = min(ans, static_cast<int>((bound - sum.begin()) - (i - 1)));
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};


/* 滑动窗口 */
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int ans = INT_MAX;
		int start = 0,
			end = 0;
		int sum = 0;
		while (end < n) {
			sum += nums[end];
			// start
			while (sum >= s) {
				ans = min(ans, end - start + 1);
				sum -= nums[start];
				start++;
			}
			end++;
		}
		return ans == INT_MAX ? 0 : ans;
	}
};

