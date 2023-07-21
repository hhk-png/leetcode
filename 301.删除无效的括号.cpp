#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

/*
给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 任意顺序 返回。

 

示例 1：

输入：s = "()())()"
输出：["(())()","()()()"]
示例 2：

输入：s = "(a)())()"
输出：["(a())()","(a)()()"]
示例 3：

输入：s = ")("
输出：[""]


*/

class Solution {
public:
	// 判断 str 括号集是否符合有效
	bool isValid(string str) {
		int count = 0;

		for (char c : str) {
			if (c == '(') {
				++count;
			} else if (c == ')') {
				--count;
				// 当 count 小于0时，可以直接返回 false
				if (count < 0) {
					return false;
				}
			}
		}

		return count == 0;
	}

	vector<string> removeInvalidParentheses(string s) {
		// 存储最终结果
		vector<string> ans;
		// 当前正在遍历队列
		unordered_set<string> currSet;

		// 初始的时候先填入原字符串 
		currSet.insert(s);
		// 无限循环，直到找到结果
		//	每进行一次 while 循环，currSet 里面字符串的字符数就减少1
		while (true) {
			// 遍历 currSet，找到正确的字符串，
			for (auto& str : currSet) {
				if (isValid(str)) {
					ans.emplace_back(str);
				}
			}

			// 一旦找到，就可以直接返回结果
			if (ans.size() > 0) {
				return ans;
			}

			// 由 currSet 推断出 nextSet
			unordered_set<string> nextSet;
			for (auto& str : currSet) {
				// 遍历 str 的每个字母
				for (int i = 0; i < str.size(); ++i) {
					// '((' 或 '))' 这两种情况
					if (i > 0 && str[i] == str[i - 1]) {
						continue;
					}
					// 忽略除 '(' 和 ')' 以外的字符，字母可以忽略
					if (str[i] == '(' || str[i] == ')') {
						// 拼接 [0, i - 1] 和 [i + 1, size] 范围内的字符串
						//	也就是将 str 除掉 i 位置的字符之后加入到 nextSet 中
						nextSet.insert(str.substr(0, i) + str.substr(i + 1));
					}
				}
			}
			// 进入下一轮遍历
			currSet = nextSet;
		}
	}
};


class Solution {
public:
	bool isValid(const string & str) {
		int cnt = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				cnt++;
			}
			else if (str[i] == ')') {
				cnt--;
				if (cnt < 0) {
					return false;
				}
			}
		}

		return cnt == 0;
	}
	vector<string> res;

	vector<string> removeInvalidParentheses(string s) {
		// 字符串中最少需要去掉的左括号和右括号的数目
		int lremove = 0;
		int rremove = 0;
		for (char c : s) {
			if (c == '(') {
				++lremove;
			}
			else if (c == ')') {
				if (lremove == 0) {
					++rremove;
				}
				else {
					--lremove;
				}
			}
		}

		helper(s, 0, lremove, rremove);
		return res;
	}

	void helper(string str, int start, int lremove, int rremove) {
		// str 中左右括号的数目已经相同
		if (lremove == 0 && rremove == 0) {
			if (isValid(str)) {
				res.push_back(str);
			}
			return;
		}

		for (int i = start; i < str.size(); ++i) {
			if (i != start && str[i] == str[i - 1]) {
				continue;
			}

			// 如果将要删除的字符数已经大于剩余字符串的长度，则停止
			if (lremove + rremove > str.size() - i) {
				return;
			}

			// 去掉一个左括号
			if (lremove > 0 && str[i] == '(') {
				// 开始位置传入的是 i，也就是当前 str 的 i + 1 位置
				helper(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);
			}

			// 去掉一个右括号
			if (rremove > 0 && str[i] == ')') {
				helper(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
			}
		}
	}
};
