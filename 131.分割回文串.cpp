/*
	给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

	返回 s 所有可能的分割方案。

	示例:
	输入: "aab"
	输出:
	[
	  ["aa","b"],
	  ["a","a","b"]
	]

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/palindrome-partitioning
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



class Solution {
public:
	// 是否是回文串，简单判断
	bool isPalindrome(string res) {
		int left = 0;
		int right = res.length() - 1;
		while (left < right) {
			if (res[left] != res[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		if (s == "") return res;
		vector<string> cur;
		dfs(s, res, cur);

		return res;
	}

	// 需要加上"&"表示传递的是引用，
	void dfs(string s, vector<vector<string>>& res, vector<string>& cur) {
		// s为空时，说明cur里面分割的字符全都是回文串，
		//  push到res中
		if (s == "") {
			res.push_back(cur);
			return;
		}

		for (int i = 1; i <= s.length(); i++) {
			// 截取0 - i
			string pre = s.substr(0, i);
			if (isPalindrome(pre)) {
				cur.push_back(pre);
				// 截取i - (last)，进行dfs
				dfs(s.substr(i, s.length() - i), res, cur);
				cur.pop_back();
			}

		}
	}
};



