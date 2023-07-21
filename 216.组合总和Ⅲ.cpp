#include<iostream>
#include<vector>
#include<numeric> // accumulate
using namespace std;

/*
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

 

示例 1:
	输入: k = 3, n = 7
	输出: [[1,2,4]]
	解释:
		1 + 2 + 4 = 7
		没有其他符合的组合了。

示例 2:
	输入: k = 3, n = 9
	输出: [[1,2,6], [1,3,5], [2,3,4]]
	解释:
		1 + 2 + 6 = 9
		1 + 3 + 5 = 9
		2 + 3 + 4 = 9
		没有其他符合的组合了。
示例 3:
	输入: k = 4, n = 1
	输出: []
	解释: 不存在有效的组合。
	在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。

*/

class Solution {
public:
	vector<int> temp;
	vector<vector<int>> res;

	void dfs(int cur, int n, int k, int sum) {
		// 剪枝
		// temp的大小加上剩余数字的个数小于k
		// temp的大小大于 k
		if ((temp.size() + (n - cur + 1) < k) || temp.size() > k) {
			return;
		}

		// temp的大小等于k，且数组所有元素的和为sum
		if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
			res.push_back(temp);
			return;
		}

		// 处理当前cur
		temp.push_back(cur);
		dfs(cur + 1, n, k, sum);
		temp.pop_back();
		dfs(cur + 1, n, k, sum);

	}

	vector<vector<int>> combinationSum3(int k, int n) {
		dfs(1, 9, k, n);
		return res;
	}
};


class Solution {
public:
	vector<int> temp;
	vector<vector<int>> res;

	bool check(int mask, int k, int sum) {
		temp.clear();
		for (int i = 0; i < 9; ++i) {
			if ((1 << i) & mask) {
				temp.push_back(i + 1);
			}
		}

		return temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum;
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		// mask 会通过二进制枚举所有可能的情况，范围在1-9的数字的所有可能的情况
		for (int mask = 0; mask < (1 << 9); ++mask) {
			if (check(mask, k, n)) {
				res.push_back(temp);
			}
		}

		return res;
	}
};

class Solution {
public:
	vector<int> temp;
	vector<vector<int>> res;

	bool num(int mask, int k) {
		int count = 0;
		int ans = 0;
		while (ans = mask & (mask - 1)) {
			count++;
			mask = ans;
		}
		if (count > k) {
			return true;
		}
		return false;
	}

	bool check(int mask, int k, int sum) {
		temp.clear();

		// 如果 mask 转换为二进制后 1 的个数大于 k，可以直接返回
		if (num(mask, k)) {
			return false;
		}

		for (int i = 0; i < 9; ++i) {
			if ((1 << i) & mask) {
				temp.push_back(i + 1);
			}
		}

		return temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum;
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		for (int mask = 0; mask < (1 << 9); ++mask) {
			if (check(mask, k, n)) {
				res.push_back(temp);
			}
		}

		return res;
	}
};


