class Solution {
public:
	// 正则表达式匹配
	// 动态规划
	bool isMatch(string s, string p) {
		// 初始化，获取匹配模式和字符串的长度
		int m = s.size();
		int n = p.size();
		bool f[100][100] = false;
		f[0][0] = true;

		// 预处理，不知道为什么
		for (int i = 1; i <= n; i++) {
			f[0][i] = p[i - 1] == '*' && f[0][i - 2];
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				// 相等匹配
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
					f[i][j] = f[i - 1][j - 1];
				}
				// 为*时的情况
				if (p[j - 1] == '*') {
					if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
						f[i][j] = f[i][j - 2] || f[i - 1][j];
					}
					else {
						f[i][j] = f[i][j - 2];
					}
				}
			}
		}

		return f[m][n];

	}
};