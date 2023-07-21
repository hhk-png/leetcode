#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
	int dfs(const string& s, int left, int right, int k) {
		// cnt 统计 [left, right] 范围内字符串 s 中字母出现的次数
		vector<int> cnt(26, 0);
		for (int i = left; i <= right; ++i) {
			++cnt[s[i] - 'a'];
		}

		// 从0(a) 遍历到 26(z)，找到第一个出现次数小于 k 的字母，
		//		记为 split
		char split = 0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] > 0 && cnt[i] < k) {
				split = i + 'a';
				break;
			}
		}
		// 如果所有的字母出现次数都大于 k，则直接返回子串的长度
		if (split == 0) {
			return right - left + 1;
		}

		int i = left;
		int ret = 0;
		// [left, right] 范围内可能有多个 split
		while (i <= right) {
			// 跳过split
			while (i <= right && s[i] == split) {
				i++;
			}
			// 如果此时超过了对应的范围，遍历结束
			if (i > right) {
				break;
			}
			// 跳过了split之后，遍历坐标开始的位置
			int start = i;
			// 向前走，直到遇到 split 字母，此时 split 之前的符合规则的字母的坐标为 i - 1
			while (i <= right && s[i] != split) {
				i++;
			}

			// [start, i - 1]
			int length = dfs(s, start, i - 1, k);
			// 
			ret = max(ret, length);
		}

		return ret;
	}

	int longestSubstring(string s, int k) {
		int n = s.length();
		dfs(s, 0, n - 1, k);
	}
};
