// https://leetcode.cn/problems/word-ladder-ii/submissions/

class Solution {
public:
    vector<vector<string>> res;
    // ��¼���ʽ�����һ���ڵ�����ĵ���
    unordered_map<string, set<string>> wordToNext;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // �����ж���չ���ĵ����Ƿ��� wordList ����
        unordered_set<string> dict = { wordList.begin(), wordList.end() };
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        // �ﵽ�˶�Ӧ�ĵ��ʽڵ㣬�ͽ���Ӧ�ĵ���ɾ��
        dict.erase(beginWord);

        // ��¼·���ϵĵ��ʶ�Ӧ�Ĳ���
        unordered_map<string, int> wordToStep = { {beginWord, 0} };
        wordToNext.insert(pair<string, set<string>>(beginWord, {}));
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{ {beginWord} };
        while (!q.empty()) {
            // ÿ����һ��queue������һ��step
            step++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string currWord = q.front();
                q.pop();
                // Ѱ��currWord �ܹ�����ģ�������wordList �еĵ���
                string nextWord = currWord;
                for (int j = 0; j < currWord.size(); ++j) {
                    // ���ڻ���
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
