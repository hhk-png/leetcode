#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

/*

给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 upper）之内的 区间和的个数 。

区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

 
示例 1：
	输入：nums = [-2,5,-1], lower = -2, upper = 2
	输出：3
	解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。

示例 2：
	输入：nums = [0], lower = 0, upper = 0
	输出：1

*/

class Solution {
public:
	int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
		if (left == right) {
			return 0;
		}
		else { // 通过归并排序的过程将 n^2 的某个 n 降低到 logn
			// [left, right] 区间的中位数
			int mid = left + (right - left) / 2;
			// 统计区间 [left, mid]
			int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
			// 统计区间 [mid + 1, right]
			int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
			// 两个区间已经计算的结果
			int ret = n1 + n2;

			// sum数组区间 [left, mid] 和 [mid + 1, right] 内的元素是有序的
			//	计算有序数组的区间和要比计算无序数组的区间和要少做一些事情

			// i 从 left 到 mid
			int i = left;
			// lower
			int l = mid + 1;
			// upper
			int r = mid + 1;
			while (i <= mid) {
				// l 停在区间和大于或等于 lower 的地方
				while (l <= right && (sum[l] - sum[i] < lower)) l++;
				// r 停在区间和大于 upper 的地方，如果 r 在大于等于 upper 的地方停下来，则 ret 需要再加一
				while (r <= right && (sum[r] - sum[i] <= upper)) r++;
				// (r - l) 刚好是符合要求的个数
				ret += (r - l);
				// i 递增
				i++;
			}

			// 归并过程
			vector<long> sorted(right - left + 1);
			int p1 = left, p2 = mid + 1;
			int p = 0;
			while (p1 <= mid || p2 <= right) {
				if (p1 > mid) {
					sorted[p++] = sum[p2++];
				}
				else if (p2 > right) {
					sorted[p++] = sum[p1++];
				}
				else {
					if (sum[p1] < sum[p2]) {
						sorted[p++] = sum[p1++];
					}
					else {
						sorted[p++] = sum[p2++];
					}
				}
			}

			// 更新原数组
			for (int i = 0; i < sorted.size(); ++i) {
				sum[left + i] = sorted[i];
			}

			// 返回结果
			return ret;
		}
	}

	int countRangeSum(vector<int>& nums, int lower, int upper) {
		// 计算数组的前缀和，数组的第一个元素置 0
		long s = 0;
		vector<long> sum = { 0 };
		for (int num : nums) {
			s += num;
			sum.push_back(s);
		}
		return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
	}
};



/* 没看懂 */


class BIT {
private:
	int n;
	vector<int> tree;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	// t[x]节点的父节点为t[x+ lowbit(x)]

	static constexpr int lowbit(int x) {
		return x & (-x);
	}

	// 从根节点更新树的值
	void update(int x, int d) {
		while (x <= n) {
			tree[x] += d;
			// 转移到父节点
			x += lowbit(x);
		}
	}

	int query(int x) const {
		int ans = 0;
		while (x) {
			ans += tree[x];
			// 向这个点左上角找到一个节点，查询这个节点的前缀和
			x -= lowbit(x);
		}
		return ans;
	}
};

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		// 求前缀和
		long long sum = 0;
		vector<long long> preSum = { 0 };
		for (int num : nums) {
			sum += num;
			preSum.push_back(sum);
		}

		// 将 x - lower，x - upper，x 放入到 allNumbers 中
		set<long long> allNumbers;
		for (long long x : preSum) {
			allNumbers.insert(x);
			allNumbers.insert(x - lower);
			allNumbers.insert(x - upper);
		}

		// 利用哈希表进行离散化
		//  value : index
		unordered_map<long long, int> values;
		int idx = 0;
		for (long long x : allNumbers) {
			values[x] = idx;
			idx++;
		}

		int ret = 0;
		BIT bit(values.size());
		for (int i = 0; i < preSum.size(); i++) {
			int left = values[preSum[i] - upper],
				right = values[preSum[i] - lower];
			ret += bit.query(right + 1) - bit.query(left);
			bit.update(values[preSum[i]] + 1, 1);
		}
		return ret;
	}
};


