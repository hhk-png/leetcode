#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*
给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。

 

示例 1：
	输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
	输出：16
	解释：这两个单词为 "abcw", "xtfn"。

示例 2：
	输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
	输出：4
	解释：这两个单词为 "ab", "cd"。

示例 3：
	输入：words = ["a","aa","aaa","aaaa"]
	输出：0
	解释：不存在这样的两个单词。
*/

class Solution {
public:
	int maxProduct(vector<string>& words) {
		// 字符数组长度
		int n = words.size();
		vector<int> masks(n);
		// 将 words 中的所有单词通过二进制映射到数组上
		for (int i = 0; i < words.size(); ++i) {
			string word = words[i];
			int wordLen = word.size();
			for (int j = 0; j < wordLen; ++j) {
				// 后面的 word[j] - 'a' 需要带上括号
				//  编译器从后往前计算
				masks[i] |= 1 << (word[j] - 'a');
			}
		}

		// 计算单词长度的最大乘积
		// 存储最大值
		int maxVal = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				// 如果两者相与为 0，则说明不存在某个位都为 1
				//  & 的优先级小于 == ，需要加括号
				if ((masks[i] & masks[j]) == 0) {
					// 计算最大值
					//  int 转换
					maxVal = max(maxVal, int(words[i].size() * words[j].size()));
				}
			}
		}

		return maxVal;
	}
};



// 优化
// 如果数组 words 中存在由相同的字母组成的不同单词，则会造成不必要的重复计算。
//  如果有多个单词的位掩码相同，则只需要记录该位掩码对应的最大单词长度即可。
class Solution {
public:
	int maxProduct(vector<string>& words) {
		unordered_map<int,int> map;
		int length = words.size();
		for (int i = 0; i < length; i++) {
			int mask = 0;
			string word = words[i];
			int wordLength = word.size();
			for (int j = 0; j < wordLength; j++) {
				mask |= 1 << (word[j] - 'a');
			}
			if(map.count(mask)) {
				if (wordLength > map[mask]) {
					map[mask] = wordLength;
				}
			} else {
				map[mask] = wordLength;
			}

		}
		int maxProd = 0;
		for (auto [mask1, _] : map) {
			int wordLength1 = map[mask1];
			for (auto [mask2, _] : map) {
				if ((mask1 & mask2) == 0) {
					int wordLength2 = map[mask2];
					maxProd = max(maxProd, wordLength1 * wordLength2);
				}
			}
		}
		return maxProd;
	}
};


