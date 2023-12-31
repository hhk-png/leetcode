﻿/*
	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

	注意：
	假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 

	示例 1：
	输入：x = 123
	输出：321

	示例 2：
	输入：x = -123
	输出：-321

	示例 3：
	输入：x = 120
	输出：21

	示例 4：
	输入：x = 0
	输出：0

	提示：
	-2^31 <= x <= 2^31 - 1
*/

class Solution {
public:
	int reverse(int x) {
		int rev = 0;

		/* 主要逻辑，与字符串反转类似
			
			int pop = x % 10;
			x /= 10;
			rev = rev * 10 + pop;
		*/

		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}

		return rev;
	}
};