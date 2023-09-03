// https://leetcode.cn/problems/word-ladder-ii/submissions/

class Solution {
public:
    vector<vector<string>> res;
    // 记录单词进入下一个节点后进入的单词
    unordered_map<string, set<string>> wordToNext;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 用于判断扩展出的单词是否在 wordList 里面
        unordered_set<string> dict = { wordList.begin(), wordList.end() };
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        // 达到了对应的单词节点，就将对应的单词删除
        dict.erase(beginWord);

        // 记录路径上的单词对应的步数
        unordered_map<string, int> wordToStep = { {beginWord, 0} };
        wordToNext.insert(pair<string, set<string>>(beginWord, {}));
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{ {beginWord} };
        while (!q.empty()) {
            // 每遍历一次queue，就是一个step
            step++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string currWord = q.front();
                q.pop();
                // 寻找currWord 能够到达的，并且在wordList 中的单词
                string nextWord = currWord;
                for (int j = 0; j < currWord.size(); ++j) {
                    // 用于回溯
                    char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (wordToStep[nextWord] == step) {
                            wordToNext[nextWord].insert(currWord);
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        dict.erase(nextWord);
                        q.push(nextWord);
                        wordToNext[nextWord].insert(currWord);
                        wordToStep[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            vector<string> path = { endWord };
            backtrack(endWord, path);
        }
        return res;
    }

    void backtrack(const string& word, vector<string>& path) {
        if (wordToNext[word].empty()) {
            res.push_back({ path.rbegin(), path.rend() });
            return;
        }
        for (const string& Parent : wordToNext[word]) {
            path.push_back(Parent);
            backtrack(Parent, path);
            path.pop_back();
        }
    }
};
