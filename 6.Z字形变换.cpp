#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：
	输入：s = "PAYPALISHIRING", numRows = 3
	输出："PAHNAPLSIIGYIR"

示例 2：
	输入：s = "PAYPALISHIRING", numRows = 4
	输出："PINALSIGYAHRPI"
	解释：
		P     I    N
		A   L S  I G
		Y A   H R
		P     I

示例 3：
	输入：s = "A", numRows = 1
	输出："A"

*/

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		// 存储 s 中需要放到第 i 行的字符
		//  行数需要根据 numRows 和 s.size() 的最小值确定
		vector<string> rows(min(numRows, int(s.size())));
		// 当前的行数，在 rows 中
		int currRow = 0;
		// 是否向下走，初始为 false
		bool goingDown = false;
		for (char c : s) {
			// 向对应的行中添加字符
			rows[currRow] += c;
			// 如果处在第一行或者最后一行，需要转换方向
			if (currRow == 0 || currRow == numRows - 1) {
				goingDown = !goingDown;
			}
			// 根据方向决定加 1 还是减 1
			currRow += goingDown ? 1 : -1;
		}

		// 将字符串拼在一块
		string res;
		for (string& row : rows) {
			res += row;
		}

		return res;
	}
};
