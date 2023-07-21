#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/* https://leetcode.cn/problems/concatenated-words/

给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。

连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。

 
示例 1：
    输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
    输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
    解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成;
         "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成;
         "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
示例 2：
    输入：words = ["cat","dog","catdog"]
    输出：["catdog"]

*/


// 字典树
struct Trie {
    // 当前节点是否是一个单词的末尾
    bool isEnd;
    vector<Trie*> children;
    Trie() {
        this->isEnd = false;
        this->children = vector<Trie*>(26, nullptr);
    }
};

class Solution {
public:
    Trie* trie = new Trie();
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // 将words 中字符串按长度递增排序，
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.size() < b.size();
        });
        // 存放结果
        vector<string> result;
        // 遍历words
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            // 若字符串的大小为0，跳过此次dfs
            if (word.size() == 0) continue;
            // 每个word 都要重置一个visited
            vector<int> visited(word.size(), 0);
            // 如果遍历到了word 的末尾字符，并且节点的isEnd 为true
            if (dfs(word, 0, visited)) { // 此时说明word 是由words 中的字符串拼接成的，
                result.emplace_back(word);
            } else { // 将word 插入字典树中
                insert(word);
            }
        }

        return result;
    }

    // dfs 的过程中可能多次从根节点开始遍历
    bool dfs(const string& word, int start, vector<int>& visited) {
        // 此判断对应的是word 最后一个字符是末尾节点
        //  如果没有到word 的最后一个字符，还是要继续遍历剩余的字符
        if (start == word.size()) {
            return true;
        }
        // 如果start 已经访问过，对应的是单个字符串由同一个字符串拼接的情况，因为words没有重复项
        if (visited[start]) {
            return false;
        }
        Trie* node = trie;
        // 设置为已访问
        visited[start] = true;
        for (int i = start; i < word.size(); i++) {
            int index = word[i] - 'a';
            node = node->children[index];
            if (node == nullptr) {
                return false;
            }
            // 到达了末尾
            if (node->isEnd) {
                // 开始处理下一个字符
                if (dfs(word, i + 1, visited)) {
                    return true;
                }
            }
        }
        // 字符串的dfs 停留在半路，返回false
        return false;
    }

    // 字典树的插入
    void insert(const string& word) {
        // 获取根节点
        Trie* node = trie;
        // 将word 中的字符依此插入字典树中
        for (int i = 0; i < word.size(); i++) {
            // 子节点的位置索引
            int index = word[i] - 'a';
            // 如果为空，说明之前没有查如果此字符
            if (node->children[index] == nullptr) {
                // 将此节点点亮
                node->children[index] = new Trie();
            }
            // 进入下一个节点
            node = node->children[index];
        }
        // 此时的node指向的是字符串的末尾节点，将该节点的isEnd 设置为true
        node->isEnd = true;
    }
};

