#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/*
DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

例如，"ACGAATTCCG" 是一个 DNA序列 。
在研究 DNA 时，识别 DNA 中的重复序列非常有用。

给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。

 

示例 1：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
*/

class Solution {
public:
	const int L = 10;
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> map;
		int n = s.size();
		vector<string> res;
		for (int i = 0; i <= n - L; i++) {
			string ans = s.substr(i, L);
			if (++map[ans] == 2) {
				res.push_back(ans);
			}
		}
		return res;
	}
};

// 二进制
class Solution {
public:
	const int L = 10;
	unordered_map<char, int> bin = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		int n = s.length();
		if (n < L) {
			return res;
		}
		int x = 0;
		// i: 0 ~ L-2
		for (int i = 0; i < L - 1; i++) {
			x = (x << 2) | bin[s[i]];
		}
		unordered_map<int, int> map;
		for (int i = 0; i <= n - L; i++) {
			x = ((x << 2) | bin[s[i + L - 1]])
				& ((1 << (L * 2)) - 1); // 二进制 1 向左移 20 位，然后减 1
			if (++map[x] == 2) {
				res.push_back(s.substr(i, L));
			}
		}

		return res;
	}
};

