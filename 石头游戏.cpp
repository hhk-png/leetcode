#include<iostream>
#include<vector>
using namespace std;

// 自定义一个元组
class Pair {
	int fir, sec;
	Pair(int fir, int sec) {
		this->fir = fir;
		this->sec = sec;
	}
};

int stoneGame(int piles[]) {
	// 石子堆数
	int n = piles.size();

	// 初始化dp数组，应该不对
	vector<vector<Pair>> dp(n, vector<Pair>(n));

	// 对数组内的元素进行初始化
	// 斜着遍历
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			dp[i][j] = new Pair(0, 0);
	
	// 初始化对角线上的数据
	for (int i = 0; i < n; i++) {
		dp[i][i].fir = piles[i];
		dp[i][i].sec = 0;
	}

	// l：长度，i：左边界，j：右边界
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			// 由l和i计算出右边界
			int j = n - i + 1;

			// 先手选择最左边所得的分数
			// 如果先手选择最左边，那么对于[i, j]来说就是后手选择右边的石子
			int left = piles[i] + dp[i + 1][j].sec;
			// 先手选择最右边
			int right = piles[j] + dp[i][j - 1].sec;

			// 比较大小，
			if (left > right) {
				// 说明[i, j]区间先手左边的收益最大
				dp[i][j].fir = left;
				// 如果是后手，那么对于区间的另一半就是先手
				dp[i][j].sec = dp[i + 1][j].fir;
			} else {
				dp[i][j].fir = right;
				dp[i][j].sec = dp[i][j - 1].fir;
			}
		}
	}

	// 存放最终结果的元组
	Pair res = dp[0][n - 1];

	return res.fir - res.sec;
}