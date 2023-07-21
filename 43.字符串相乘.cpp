// 输入: num1 = "123", num2 = "456"
// 输出 : "56088"
// 问题：m的含义
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0') return "0"; // 特判

		int n = num1.size() + num2.size();// 两数相乘结果的位数小于两数各自位数之和
											// 用来决定最终结果的位数
		string res(n, '0');

		for (int i = num1.size() - 1; i >= 0; i--) {

			int m = n - 1, mbit = 0, abit = 0;  //mbit乘法进位，abit加法进位

			for (int k = num1.size() - i - 1; k > 0; k--)  //保证错位相加
				m--; 

			for (int j = num2.size() - 1; j >= 0; j--, m--) {
				// 两个数字相乘
				int multi = (num1[i] - '0')*(num2[j] - '0') + mbit;
				// 乘数的进位
				mbit = multi / 10;
				// 乘数的个位 + 之前加法的进位 + 当前位置的数字 = 新的当前位置的主子
				int add = res[m] - '0' + multi % 10 + abit;
				res[m] = add % 10 + '0';
				// 计算过后的加法进位
				abit = add / 10;
			}

			// num1与num2的一个数字相乘后的收尾部分
			if (mbit)
				res[m] += mbit;
			if (abit)
				res[m] += abit;
		}

		// 整合
		for (int i = 0; i < res.size(); i++)
			if (res[i] != '0')
				return res.substr(i);
		return "";
	}
};