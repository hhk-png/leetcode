#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int left = 0, // �������λ��
			right = 0, // �����Ҳ�λ��
			start = 0, // ��С�Ӵ���ʼλ��
			minLen = INT_MAX, //��С�ִ�����
			match = 0; // �����з���target�ַ��ĸ��������ڳ���ִ�й�����
		unordered_map<char, int> window; // ����ӳ��
		unordered_map<char, int> needs; // targetӳ��
		for (char c : t) needs[c]++;

		while (right < s.size()) {
			// �Ҳ����󴰿�
			char c1 = s[right];
			if (needs.count(c1)) { // 
				window[c1]++;
				// 
				if (window[c1] == needs[c1])
					match++;
			}
			right++;

			// �����Ҷ���չ�������ǵ��ִ�����Ҫ��
			// ���ߴ��������С�������ǵ��ִ�����Ҫ��
			while (match == needs.size()) {

				// ������С���ڵ�����
				if (right - left < minLen) {
					start = left;
					minLen = right - left;
				}

				// �����С����
				char c2 = s[left];
				if (needs.count(c2)) {
					window[c2]--;
					if (window[c2] < needs[c2])
						match--��
				}
				left++;
			}
		}

		return minLen == INT_MAX ? "" : s.substr(start, minLen);
	}
};