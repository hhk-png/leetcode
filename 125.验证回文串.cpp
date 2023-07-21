/*
	����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

	˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

	ʾ�� 1:
	����: "A man, a plan, a canal: Panama"
	���: true

	ʾ�� 2:
	����: "race a car"
	���: false

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/valid-palindrome
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


// ˫ָ�뷨
class Solution {
public:
	bool isPalindrome(string s) {
		int n = s.size();
		int left = 0, right = n - 1;
		while (left < right) {
			while (left < right && !isalnum(s[left])) {
				++left;
			}
			while (left < right && !isalnum(s[right])) {
				--right;
			}
			if (left < right) {
				if (tolower(s[left]) != tolower(s[right])) {
					return false;
				}
				++left;
				--right;
			}
		}
		return true;
	}
};
