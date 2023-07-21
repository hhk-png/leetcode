class Solution {
public:
	int countSubstrings(string s) {

		vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
		int ans = 0;

		for (int j = 0; j < s.length(); j++) {
			for (int i = 0; i <= j; i++) {
				if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
					dp[i][j] = true;
					ans++;
				}
			}
		}

		return ans;
	}
};