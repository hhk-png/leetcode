#include<iostream>
#include<unordered_map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

/*
使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

 

示例 1：
	输入：s1 = "great", s2 = "rgeat"
	输出：true
	解释：s1 上可能发生的一种情形是：
		"great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
		"gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
		"gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
		"g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
		"r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
		"r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
	算法终止，结果字符串和 s2 相同，都是 "rgeat"
	这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true

示例 2：
	输入：s1 = "abcde", s2 = "caebd"
	输出：false

示例 3：
	输入：s1 = "a", s2 = "a"
	输出：true

*/

class Solution {
private:
	// 记忆化搜索存储状态的数组
	// -1 表示 false，1 表示 true，0 表示未计算
	int memo[30][30][31];
	string s1, s2;

	// 检查 s1 和 s2 从 i1 i2 位置开始各字符是否相同
	bool checkIfSimiliar(int i1, int i2, int length) {
		// 频率计数
		unordered_map<char, int> freq;
		for (int i = i1; i < i1 + length; ++i) {
			++freq[s1[i]];
		}
		for (int i = i2; i < i2 + length; ++i) {
			--freq[s2[i]];
		}
		// 经过两次遍历后，保证所有字符的频数为 0
		if (any_of(freq.begin(), freq.end(), [](const auto& entry) { return entry.second != 0; })) {
			return false;
		}

		return true;
	}

	bool dfs(int i1, int i2, int length) {
		// 该位置已经计算过，为 1
		if (memo[i1][i2][length]) {
			return memo[i1][i2][length] == 1;
		}

		// 字符相同
		// s1 从 i1 开始，长度为length，与 s2 是否相同
		if (s1.substr(i1, length) == s2.substr(i2, length)) {
			// 若相同，此位置的值为 1 
			memo[i1][i2][length] = 1;
			return true;
		}

		// 特判
		// 字符的频数相同
		// 两个字符串的字符频数不相同
		if (!checkIfSimiliar(i1, i2, length)) {
			// 也就不是扰乱后的字符串
			memo[i1][i2][length] = -1;
			return false;
		}

		// 开始移动指针
		for (int i = 1; i < length; ++i) {
			// 不交换的情况
			if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
				memo[i1][i2][length] = 1;
				return true;
			}

			// 交换的情况
			// 固定 i1 移动 i2 的指针，并且固定 i2 ，移动 i1 的指针
			if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
				memo[i1][i2][length] = 1;
				return true;
			}
		}

		memo[i1][i2][length] = -1;
		return false;

	}

public:
	bool isScramble(string s1, string s2) {
		// 分配内存空间
		memset(memo, 0, sizeof(memo));
		this->s1 = s1;
		this->s2 = s2;
		// s1 与 s2 长度相同
		return dfs(0, 0, s1.size());
	}
};

