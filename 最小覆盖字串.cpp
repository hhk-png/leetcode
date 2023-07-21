#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int left = 0,
			right = 0,
			start = 0,
			minLen = INT_MAX;
		string res = s;
		unordered_map<char, int> window;
		unordered_map<char, int> needs;
		for (char c : t) needs[c]++;

		int match = 0; // ��¼����Ҫ���ַ��ĸ���

		while (right < s.size()) {

			// �Ҳ����󴰿�
			char c1 = s[right];
			if (needs.count(c1)) {
				window[c1]++;
				if (window[c1] == needs[c1])
					match++;
			}
			right++;
			
			while (match == needs.size()) {

				// ��¼����Ҫ����ִ���ʼλ�ã��ͳ���
				if (right - left < minLen) {
					start = left;
					minLen = right - left;
				}

				// �����С����
				char c2 = s[left];
				if (needs.count(c2)) {
					window[c2]--;
					if (window[c2] < needs[c2])
						match--;
				}
				left++;
			}
		}
		return minLen == INT_MAX ?
			"" : s.substr(start, minLen);
	}
};