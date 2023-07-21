class Solution {
public:
	bool canWinNim(int n) {
		if (n <= 3) return true;
		// dp数组中存放的状态为是否胜利
		vector<bool> dp(n + 1);
		dp[1] = true;
		dp[2] = true;
		dp[3] = true;

		for (int i = 4; i <= n; i++) {
			// 要想先手胜利，那么先前拿石子的那个人必定有一个输的状态
			dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
		}

		return dp[n];
	}
};