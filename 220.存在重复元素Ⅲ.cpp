#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

 

示例 1：
	输入：nums = [1,2,3,1], k = 3, t = 0
	输出：true

示例 2：
	输入：nums = [1,0,1,1], k = 1, t = 2
	输出：true

示例 3：
	输入：nums = [1,5,9,1,5,9], k = 2, t = 3
	输出：false

*/

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

		/*
		对于序列中每一个元素 xx 左侧的至多 kk 个元素，
			如果这 kk 个元素中存在一个元素落在区间 [x - t, x + t][x−t,x+t] 中，
			我们就找到了一对符合条件的元素。*/

		int n = nums.size();
		set<int> rec;
		
		for (int i = 0; i < n; ++i) {
			// x - t
			// 防止 nums[i] 溢出
			auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
			// iter 存在，且小于等于 x + t
			if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
				return true;
			}
			// 插入 nums[i]，保证 rec 的大小为 k - 1
			rec.insert(nums[i]);
			if (i >= k) {
				// 删除最先进入的元素
				rec.erase(nums[i - k]);
			}
		}

		return false;
	}
};



class Solution {
public:
	// x 的桶编号
	int getID(int x, long w) {
		return x < 0 ? (x + 1ll) / w - 1 : x / w;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		// 桶内最多一个元素，用哈希表作为桶就可以
		unordered_map<int, int> map;
		// 数组大小
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			long x = nums[i];
			// 桶的 id
			int id = getID(x, t + 1ll);

			// 在同一个桶，桶的大小为 k - 1
			if (map.count(id)) {
				return true;
			}

			// 前一个桶或者后一个桶内存在对应元素
			if (map.count(id - 1) && abs(x - map[id - 1]) <= t) {
				return true;
			}

			if (map.count(id + 1) && abs(x - map[id + 1]) <= t) {
				return true;
			}

			// 放入对应的桶内
			map[id] = x;
			// 维持桶内元素的个数
			if (i >= k) {
				map.erase(getID(nums[i - k], t + 1ll));
			}
		}

		return false;
	}
};
