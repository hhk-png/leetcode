#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int left = 0, // 窗口左侧位置
			right = 0, // 窗口右侧位置
			start = 0, // 最小子串开始位置
			minLen = INT_MAX, //最小字串长度
			match = 0; // 窗口中符合target字符的个数，用于程序执行过程中
		unordered_map<char, int> window; // 窗口映射
		unordered_map<char, int> needs; // target映射
		for (char c : t) needs[c]++;

		while (right < s.size()) {
			// 右侧增大窗口
			char c1 = s[right];
			if (needs.count(c1)) { // 
				window[c1]++;
				// 
				if (window[c1] == needs[c1])
					match++;
			}
			right++;

			// 窗口右端扩展后，所覆盖的字串符合要求
			// 或者窗口左端缩小后，所覆盖的字串符合要求
			while (match == needs.size()) {

				// 更新最小窗口的数据
				if (right - left < minLen) {
					start = left;
					minLen = right - left;
				}

				// 左侧缩小窗口
				char c2 = s[left];
				if (needs.count(c2)) {
					window[c2]--;
					if (window[c2] < needs[c2])
						match--；
				}
				left++;
			}
		}

		return minLen == INT_MAX ? "" : s.substr(start, minLen);
	}
};