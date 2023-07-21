#include<iostream>
#include<vector>
using namespace std;

/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]

*/

class Solution {
public:
	vector<int> temp;
	vector<vector<int>> ans;

	void dfs(int cur, int n, int k) {
		// 剪枝，已经装入 temp 内的数字的个数加上剩余数字的个数如果小于 k，
		//	则将不会满足条件，就可以清除这次递归
		if (temp.size() + (n - cur + 1) < k) {
			return;
		}

		// temp 的大小等于 k
		if (temp.size() == k) {
			ans.push_back(temp);
			return;
		}

		temp.push_back(cur);
		// 加入cur
		dfs(cur + 1, n, k);
		temp.pop_back();
		// 不加入cur
		dfs(cur + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k) {
		dfs(1, n, k);
		return ans;
	}
};


