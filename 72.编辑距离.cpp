/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

示例 1 :
	输入: word1 = "horse", word2 = "ros"
	输出 : 3
	解释 :
	horse->rorse(将 'h' 替换为 'r')
	rorse->rose(删除 'r')
	rose->ros(删除 'e')

示例 2 :
	输入 : word1 = "intention", word2 = "execution"
	输出 : 5
	解释 :
	intention->inention(删除 't')
	inention->enention(将 'i' 替换为 'e')
	enention->exention(将 'n' 替换为 'x')
	exention->exection(将 'n' 替换为 'c')
	exection->execution(插入 'u')
*/

// 动态规划
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		int DP[m + 1][n + 1];

		// 初始化第一行和第一列
		for (int i = 0; i < m + 1; i++) DP[i][0] = i;
		for (int j = 0; j < n + 1; j++) DP[0][j] = j;

		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				// 如果相同，就不需要进行操作，还是上一次对比的结果
				if (word1[i - 1] == word2[j - 1]) {
					DP[i][j] = DP[i - 1][j - 1];
				}
				// 不相同
				else {
					// 分别对应 删除word1[i] 删除word[j] 替换
					DP[i][j] = min(min(DP[i - 1][j] + 1, DP[i][j - 1] + 1), DP[i - 1][j - 1] + 1);
				}
			}
		}

		return DP[m][n];
	}
};