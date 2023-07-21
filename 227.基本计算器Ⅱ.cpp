#include<iostream>
#include<string>
#include<numeric> // accumulate
#include<vector>
#include<locale> // isdigit
using namespace std;

/*
	给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

	整数除法仅保留整数部分。

 

	示例 1：
		输入：s = "3+2*2"
		输出：7

	示例 2：
		输入：s = " 3/2 "
		输出：1

	示例 3：
		输入：s = " 3+5 / 2 "
		输出：5
 

	提示：
		1 <= s.length <= 3 * 105
		s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
		s 表示一个 有效表达式
		表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
		题目数据保证答案是一个 32-bit 整数

*/

class Solution {
public:
	int calculate(string s) {
		vector<int> stk;
		char preSign = '+';
		int num = 0;
		int n = s.length(); // 字符串的长度
		for (int i = 0; i < n; ++i) {
			// 位置 i 处为数字
			if (isdigit(s[i])) {
				num = num * 10 + int(s[i] - '0');
			}

			// 不是数字和空格，或者 i 到达了最后一个位置
			if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
				// 在到达一个新的字符之后，处理之前字符之间的数字
				switch (preSign) {
				case '+':
					stk.push_back(num);
					break;
				case '-':
					stk.push_back(-num);
					break;
				case '*': // 如果是乘除法，就将数字计算出来之后放入原栈中
					stk.back() *= num;
					break;
				default:
					stk.back() /= num;
				}
				preSign = s[i]; // 将 preSign 换成新的运算符
				num = 0; // num 清零
			}
		}

		// 将栈中的所有元素相加，初始值为0
		return accumulate(stk.begin(), stk.end(), 0);
	}
};

