/*
	编写一个函数来查找字符串数组中的最长公共前缀。

	如果不存在公共前缀，返回空字符串 ""。


	示例 1：
	输入：strs = ["flower","flow","flight"]
	输出："fl"

	示例 2：
	输入：strs = ["dog","racecar","car"]
	输出：""
	解释：输入不存在公共前缀。
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];

		string res = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			int count = min(res.size(), strs[i].size());
			int index = 0;
			while (index < count && res[index] == strs[i][index]) {
				index++;
			}
			res = res.substr(0, index);
		}

		return res;
	}
};