#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
	int dfs(const string& s, int left, int right, int k) {
		// cnt ͳ�� [left, right] ��Χ���ַ��� s ����ĸ���ֵĴ���
		vector<int> cnt(26, 0);
		for (int i = left; i <= right; ++i) {
			++cnt[s[i] - 'a'];
		}

		// ��0(a) ������ 26(z)���ҵ���һ�����ִ���С�� k ����ĸ��
		//		��Ϊ split
		char split = 0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] > 0 && cnt[i] < k) {
				split = i + 'a';
				break;
			}
		}
		// ������е���ĸ���ִ��������� k����ֱ�ӷ����Ӵ��ĳ���
		if (split == 0) {
			return right - left + 1;
		}

		int i = left;
		int ret = 0;
		// [left, right] ��Χ�ڿ����ж�� split
		while (i <= right) {
			// ����split
			while (i <= right && s[i] == split) {
				i++;
			}
			// �����ʱ�����˶�Ӧ�ķ�Χ����������
			if (i > right) {
				break;
			}
			// ������split֮�󣬱������꿪ʼ��λ��
			int start = i;
			// ��ǰ�ߣ�ֱ������ split ��ĸ����ʱ split ֮ǰ�ķ��Ϲ������ĸ������Ϊ i - 1
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
