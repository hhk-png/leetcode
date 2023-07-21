/*

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。

例子：
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".


*/


class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
		while (i < m) {
			if (j < n && (s[i] == p[j] || p[j] == '?')) {// 相等时或为'?'时
				++i, ++j;
			}
			else if (j < n && p[j] == '*') {// 为'*'时
				iStar = i;
				jStar = j++;
			}
			else if (iStar >= 0) {// '*'与多个字符匹配时的后续操作
				i = ++iStar;
				j = jStar + 1;
			}
			else return false;
		}
		while (j < n && p[j] == '*') ++j;//去除多余星号
		return j == n;
	}
};
