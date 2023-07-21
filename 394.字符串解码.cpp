/*
	给定一个经过编码的字符串，返回它解码后的字符串。

	编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

	你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

	此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

	示例:

	s = "3[a]2[bc]", 返回 "aaabcbc".
	s = "3[a2[c]]", 返回 "accaccacc".
	s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/

class Solution {
public:
	typedef pair<string, int> pis;
	// 将str重复times次
	string repeat(const string& str, int times) {
		string returnString = "";
		for (int i = 0; i < times; i++)
			returnString += str;
		return returnString;
	}
	string decodeString(string s) {
		int repeatTimes = 0;
		string res = "";
		vector<pis> vecStack;
		for (auto i : s) {
			// 遇到数字就计算重复次数
			if ('0' <= i && i <= '9') {
				repeatTimes = (repeatTimes * 10) + (i - '0');
			}
			else if (i == '[') {
				vecStack.push_back({ res, repeatTimes });
				// 进栈后要更新res和repeatTimes
				res = "";
				repeatTimes = 0;
			}
			else if (i == ']') {
				// 遇到']'出栈
				pis tmp = vecStack[vecStack.size() - 1];
				vecStack.pop_back();
				// 拼接字符串，
				// tmp.first是前一个要被拼接的字符串
				// tmp.second是res要重复的次数
				// res要在repeat之后与tmp.first拼接
				res = tmp.first + (tmp.second == 0 ? "" : repeat(res, tmp.second));
			}
			else {
				// 添加重复的元素
				res += i;
			}
		}

		return res;
	}
};