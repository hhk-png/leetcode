/*
	给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 
	示例：
	输入："Let's take LeetCode contest"
	输出："s'teL ekat edoCteeL tsetnoc"
 

	提示：

	在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/

class Solution {
public:
	string reverseWords(string s) {
		int start;
		int index = 0;
		int length = s.length();

		while (index < length) {
			start = index;
			while (index < length && s[index] != ' ') {
				index++;
			}

			int left = start;
			int right = index - 1;
			while (left < right) {
				swap(s[left], s[right]);
				left++;
				right--;
			}

			while (index < length && s[index] == ' ') {
				index++;
			}
		}

		return s;
	}
};

class Solution {
public:
	string reverseWords(string s) {
		int start;
		int index = 0;
		int length = s.length();
		string ret;

		while (index < length) {
			start = index;
			while (index < length && s[index] != ' ') {
				index++;
			}

			for (int p = index - 1; p >= start; p--) {
				ret.push_back(s[p]);
			}

			while (index < length && s[index] == ' ') {
				ret.push_back(' ');
				index++;
			}
		}

		return ret;
	}
};