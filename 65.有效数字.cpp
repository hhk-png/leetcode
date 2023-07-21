#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

/*
	有效数字（按顺序）可以分成以下几个部分：
		一个 小数 或者 整数
		（可选）一个 'e' 或 'E' ，后面跟着一个 整数
	
	小数（按顺序）可以分成以下几个部分：
		（可选）一个符号字符（'+' 或 '-'）
		下述格式之一：
			至少一位数字，后面跟着一个点 '.'
			至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
			一个点 '.' ，后面跟着至少一位数字

	整数（按顺序）可以分成以下几个部分：
		（可选）一个符号字符（'+' 或 '-'）
		至少一位数字

	部分有效数字列举如下：
		["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]

	部分无效数字列举如下：
		["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]

	给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。

 

示例 1：
	输入：s = "0"
	输出：true

示例 2：
	输入：s = "e"
	输出：false

示例 3：
	输入：s = "."
	输出：false

	https://leetcode-cn.com/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/
*/

class Solution {
public:
	const static int S0 = 1;     // 初始状态
	const static int S1 = 2;     // 符号
	const static int S2 = 4;     // 整数
	const static int S3 = 8;     // 左无整数小数点
	const static int S4 = 16;    // 小数
	const static int S5 = 32;    // 指数e
	const static int S6 = 64;    // 指数符号
	const static int S7 = 128;   // 有效数字

	bool isNumber(string s) {
		int n = s.size();
		int state = 1;
		for (int i = 0; i < n; i++) {
			switch (state) {
			case S0: // 初始状态
				if (s[i] == '+' || s[i] == '-')
					state = S1; // 符号
				else if (isdigit(s[i]))
					state = S2; // 整数
				else if (s[i] == '.')
					state = S3; // 左边没有整数的小数点
				else
					return false; // 开头只能有以上三种状态, (符号，小数点，数字)
				break;
			case S1: // 符号
				if (isdigit(s[i]))
					state = S2; // 数字
				else if (s[i] == '.')
					state = S3; // 左无整数小数点
				else
					return false; // 符号后面只能有(数字，小数点)
				break;
			case S2: // 整数
				if (isdigit(s[i]))
					state = S2; // 整数
				else if (s[i] == '.')
					state = S4; // 数字后面跟小数点，小数
				else if (s[i] == 'e' || s[i] == 'E')
					state = S5; // e
				else
					return false;
				break;
			case S3: // 小数点后
				if (isdigit(s[i])) // 只能是数字
					state = S4; // 小数
				else
					return false;
				break;
			case S4: // 小数
				if (isdigit(s[i]))
					state = S4; // 小数后跟数字，小数状态
				else if (s[i] == 'e' || s[i] == 'E')
					state = S5; // e
				else
					return false;
				break;
			case S5:
				if (s[i] == '+' || s[i] == '-')
					state = S6; // 指数符号
				else if (isdigit(s[i]))
					state = S7; // 有效数字
				else
					return false;
				break;
			case S6:
				if (isdigit(s[i]))
					state = S7;
				else
					return false;
				break;
			case S7:
				if (isdigit(s[i]))
					state = S7;
				else
					return false;
			}
		}
		// 整数，小数，有效数字
		return state == S2 || state == S4 || state == S7;
	}
};