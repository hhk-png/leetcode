/*
	给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

	示例 :

	输入: 3
		输出 : 5
		解释 :
		给定 n = 3, 一共有 5 种不同结构的二叉搜索树 :

		1         3     3      2      1
		\       /     /      / \      \
		3     2     1      1   3      2
		/     /       \                 \
		2     1         2                 3
*/


// 动态规划
class Solution {
public:
	int numTrees(int n) {

		vector<int> G;
		G.resize(n + 1);
		G[0] = 1;
		G[1] = 1;

		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				G[i] += G[j - 1] * G[i - j];
			}
		}
		return G[n];

	}
};


// 回溯
class Solution {
public:
	int dfs(int start, int end, int *hash) {
		if (start > end) {
			return 1;
		}
		int result = 0;
		for (int i = start; i <= end; i++) {
			int left = 0;
			if (hash[i - start] == 0) {
				left = dfs(start, i - 1, hash);
				hash[i - start] = left;
			}
			else {
				left = hash[i - start];
			}
			int right = 0;
			if (hash[end - i] == 0) {
				right = dfs(i + 1, end, hash);
				hash[end - i] = right;
			}
			else {
				right = hash[end - i];
			}
			result += left * right;
		}
		return result;
	}
	int numTrees(int n) {
		int hash[100] = { 0 };
		return dfs(1, n, hash);
	}
};