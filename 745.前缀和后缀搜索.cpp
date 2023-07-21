#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/* https://leetcode.cn/problems/prefix-and-suffix-search/

设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。

实现 WordFilter 类：

WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
f(string pref, string suff) 返回词典中具有前缀 prefix 和后缀 suff 的单词的下标。如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。
 

示例：

输入
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
输出
[null, 0]
解释
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suff = "e" 。

*/

struct Trie {
    unordered_map<string, Trie*> children;
    // weight 为word 在words 中的位置
    //  最终的weight 一定会被更大的索引代替
    int weight;
};

class WordFilter {
public:
    Trie* root;
    WordFilter(vector<string>& words) {
        // 必须要进行root的初始化，否则会报内存相关的错误
        root = new Trie();
        for (int i = 0; i < words.size(); i++) {
            // 对每一个单词进行初始化
            string word = words[i];
            int m = word.size();
            // 保存根节点，
            Trie* curr = root;
            for (int j = 0; j < m; j++) {
                // 保存根节点
                Trie* tmp = curr;
                // root -> word[i]# -> word[i + 1]# -> ....
                for (int k = j; k < m; k++) {
                    string key({ word[k], '#' });
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                // 保存curr，不能是root，我也不知道为什么
                tmp = curr;
                // root -> #word[m - k - 1] -> #word[m - k + 1 - 1] -> ....
                for (int k = j; k < m; k++) {
                    string key({ '#', word[m - k - 1] });
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }

                // root -> word[j], word[m - j - 1] -> 
                string key({ word[j], word[m - j - 1] });
                if (!curr->children.count(key)) {
                    curr->children[key] = new Trie();
                }
                curr = curr->children[key];
                curr->weight = i;

            }
        }
    }

    int f(string pref, string suff) {
        int n = pref.size();
        int m = suff.size();
        int num = max(n, m);
        Trie* node = root;
        for (int i = 0; i < num; i++) {
            // 超出字符串的索引范围则为 #
            char key1 = i < n ? pref[i] : '#';
            char key2 = i < m ? suff[m - i - 1] : '#';
            // 前缀和后缀的拼接字符串
            string key({ key1, key2 });
            if (!node->children.count(key)) {
                return -1;
            }
            node = node->children[key];
        }
        return node->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */


