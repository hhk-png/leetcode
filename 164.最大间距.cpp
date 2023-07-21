#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

/*
给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。

您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。

 

示例 1:
	输入: nums = [3,6,9,1]
	输出: 3
	解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。

示例 2:
	输入: nums = [10]
	输出: 0
	解释: 数组元素个数小于 2，因此返回 0。

*/

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		// 数组长度
		int n = nums.size();
		if (n < 2) {
			return 0;
		}
		// 分位数
		int exp = 1;
		// 数组中的最大元素
		int maxVal = *max_element(nums.begin(), nums.end());
		// 用来存放 nums 的中间数组
		vector<int> buf(n);
		while (maxVal >= exp) {
			// cnt[digit] 表示：在exp分位上，数字位digit的元素的个数
			vector<int> cnt(10);
			for (int i = 0; i < n; ++i) {
				// 取出nums[i] exp分位上的数
				int digit = (nums[i] / exp) % 10;
				++cnt[digit];
			}
			// 按数字由小到大累加起来，最后 cnt[9] 的大小一定等于 n
			//	cnt 的长度为 10
			for (int i = 1; i < 10; ++i) {
				cnt[i] += cnt[i - 1];
			}
			for (int i = n - 1; i >= 0; --i) {
				int digit = (nums[i] / exp) % 10;
				// 用于存储到数组中的索引要减 1
				buf[cnt[digit] - 1] = nums[i];
				--cnt[digit];
			}
			// 用 buf 替换 nums
			copy(buf.begin(), buf.end(), nums.begin());
			exp *= 10;
		}

		// 找到相邻元素之间的最大值
		int res = 0;
		for (int i = 1; i < n; ++i) {
			res = max(res, nums[i] - nums[i - 1]);
		}
		return res;
	}
};


// https://leetcode-cn.com/problems/maximum-gap/solution/zui-da-jian-ju-by-leetcode-solution/
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		// 数组长度
		int n = nums.size();
		if (n < 2) {
			return 0;
		}
		int maxVal = *max_element(nums.begin(), nums.end());
		int minVal = *min_element(nums.begin(), nums.end());
		// 相邻数字的最大间距不会小于 d
		int d = max(1, (maxVal - minVal) / (n - 1));
		int bucketSize = (maxVal - minVal) / d + 1;

		// 第 i 个桶内的最小值一定大于第 i - 1 个桶内的最大值
		vector<pair<int, int>> bucket(bucketSize, { -1, -1 }); // 存储 (桶内最小值，桶内最大值) 对，(-1, -1) 表示该桶是空的
		for (int i = 0; i < n; ++i) {
			int idx = (nums[i] - minVal) / d;
			if (bucket[idx].first == -1) {
				bucket[idx].first = bucket[idx].second = nums[i];
			} else {
				bucket[idx].first = min(bucket[idx].first, nums[i]);
				bucket[idx].second = max(bucket[idx].second, nums[i]);
			}
		}

		// 元素之间的最大间距一定不会出现在某个桶的内部，而一定会出现在不同桶当中
		int res = 0;
		int prev = -1;
		for (int i = 0; i < bucketSize; ++i) {
			if (bucket[i].first == -1) continue;
			if (prev != -1) {
				res = max(res, bucket[i].first - bucket[prev].second);
			}
			prev = i;
		}
		return res;
	}
};
