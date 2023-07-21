/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

	示例 1:
	输入: 2
	输出 : [0, 1, 1]

	示例 2 :
	输入 : 5
	输出 : [0, 1, 1, 2, 1, 2]
*/
/* P(x) = P(x & (x − 1)) + 1; */
/* P(x) = P(x / 2) + (x mod 2) */
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ans(num + 1);
		for (int i = 1; i <= num; i++) {
			ans[i] = ans[i >> 1] + (i & 1);
		}

		return ans;
	}
};