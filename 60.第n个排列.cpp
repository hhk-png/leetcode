/*
给出集合 [1, 2, 3, …, n]，其所有元素共有 n!种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是[1, 9]。
给定 k 的范围是[1, n!]。
示例 1 :

输入: n = 3, k = 3
输出 : "213"
*/
// 迭代
class Solution {
	static const vector<int> fac;
public:
	string getPermutation(int n, int k) {
		string res;
		// 已经给定了范围
		string s = string("123456789").substr(0, n);
		--k;
		while (k > 0)
		{
			int i = k / fac[n - 1];
			res.push_back(s[i]);
			s.erase(s.begin() + i);
			k %= fac[n - 1];
			--n;
		}
		return res + s;
	}
};
const vector<int> Solution::fac = { 0,1,2,6,24,120,720,5040,40320,362880,3628800 };