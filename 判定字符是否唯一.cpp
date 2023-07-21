/*
	实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

	示例 1：
		输入: s = "leetcode"
		输出: false

	示例 2：
		输入: s = "abc"
		输出: true

*/
class Solution {
public:
	bool isUnique(string astr) {
		// 通过二进制记录字母是否出现过
		int temp = 0;
		for (char s : astr) {
			// 小写字母的数字表示需要移动的位数
			int move_bit = s - 'a';
			// 小写字母的二进制表示
			int ans = (1 << move_bit);
			// ans 的二进制表示中，只有一位为 1
			//	如果与 temp 相与后不为 0，说明存在与 s 相同的字母
			if (temp & ans) {
				return false;
			}
			else {
				// 将 s 标记到 temp 上
				temp |= ans;
			}
		}
		return true;
	}
};