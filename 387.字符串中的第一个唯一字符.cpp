#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

 

示例 1：

输入: s = "leetcode"
输出: 0
示例 2:

输入: s = "loveleetcode"
输出: 2
示例 3:

输入: s = "aabb"
输出: -1

*/

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> frequency;
		for (char ch : s) {
			++frequency[ch];
		}

		for (int i = 0; i < s.size(); i++) {
			if (frequency[s[i]] == 1) {
				return i;
			}
		}

		return -1;
	}
};

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> position;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (position.count(s[i])) {
				position[s[i]] = -1;
			}
			else {
				position[s[i]] = i;
			}
		}

		int first = n;
		for (auto [_, pos] : position) {
			if (pos != -1 && pos < n) {
				first = pos;
			}
		}

		if (first == n) {
			first = -1;
		}

		return first;
	}
};


class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> position;
		queue<pair<char, int>> que;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (!position.count(s[i])) {
				position[s[i]] = i;
				que.emplace(s[i], i);
			} else {
				position[s[i]] = -1;
				while (!que.empty() && position[que.front().first] == -1) {
					que.pop();
				}
			}
		}

		return que.empty() ? -1 : que.front().second;
	}
};

