class Solution {
public:
	bool canWinNim(int n) {
		if (n <= 3) return true;
		// dp�����д�ŵ�״̬Ϊ�Ƿ�ʤ��
		vector<bool> dp(n + 1);
		dp[1] = true;
		dp[2] = true;
		dp[3] = true;

		for (int i = 4; i <= n; i++) {
			// Ҫ������ʤ������ô��ǰ��ʯ�ӵ��Ǹ��˱ض���һ�����״̬
			dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
		}

		return dp[n];
	}
};