#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*

请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，
    返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。

*/

// 前缀树
struct TrieNode {
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};
// 前缀树插入接口
void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
public:
    WordDictionary() {
        // 根节点
        trie = new TrieNode();
    }

    void addWord(string word) {
        insert(trie, word);
    }

    bool search(string word) {
        // 参数：要识别的单词，要识别字母的索引，与字母对应的trie节点
        return dfs(word, 0, trie);
    }

    bool dfs(string& word, int index, TrieNode* node) {
        // index 到达了 word 的最后一个字母，
        //  如果当前 trie 也到达了末尾，则匹配成功
        if (index == word.size())
            return node->isEnd;
        // 要匹配的字母
        char ch = word[index];
        // 字母的情况
        if (ch >= 'a' && ch <= 'z') {
            // 子节点
            TrieNode* child = node->child[ch - 'a'];
            // 向下一个字母搜索
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        }
        // '.' 的情况
        else if (ch == '.') {
            // 需要将26个字母都遍历一遍
            for (int i = 0; i < 26; i++) {
                TrieNode* child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    TrieNode* trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
