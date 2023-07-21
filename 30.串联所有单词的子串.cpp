#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

/* https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， 
    "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，
    因为他不是任何 words 排列的连接。
返回所有串联字串在 s 中的开始索引。你可以以 任意顺序 返回答案。


*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // words的大小
        int m = words.size();
        // 指针向前移动的长度
        int n = words[0].size();
        // s 的长度
        int ls = s.size();
        vector<int> result;

        // m * n 为words 数组中字符串的总长度
        // 挨个字符遍历
        for (int i = 0; i < n && i + m * n <= ls; i++) {
            // 窗口内字符串的hash
            unordered_map<string, int> differ;
            // 先在 i 位置向后 m * n 个距离内建立 differ
            for (int j = 0; j < m; j++) {
                // 每次隔 n 个长度截取一个字符串，
                ++differ[s.substr(i + j * n, n)];
            }
            // 遍历 word 中的字符串，并在differ 中对应字符串的个数为0时 删除
            for (string& word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }

            for (int start = i; start < ls - m * n + 1; start += n) {
                // 需要向后再前进 n 个距离
                if (start != i) {
                    // 右边界前进 n
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    // 左边界前进 n
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    result.emplace_back(start);
                }
            }
        }

        return result;
    }
};
