#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

// https://leetcode.cn/problems/number-of-matching-subsequences/submissions/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<int, int>>> queues(26);
        // pair<int, int>: 字符串words[i] 目前匹配到了第 j 个位置，该位置的字母为 i + 'a'
        for (int i = 0; i < words.size(); ++i) {
            queues[words[i][0] - 'a'].emplace(i, 0);
        }
        int res = 0;
        for (char c : s) {
            // 以字母c 开头的queue
            auto& q = queues[c - 'a'];
            // 对队列中所有的匹配项进行自增
            int size = q.size();
            while (size--) {
                // 取出队头元素，
                //  i: 字符串在words 中的索引
                //  j: 字符串已经匹配到了第 j 个位置，正在匹配字母c，且匹配上了 
                auto [i, j] = q.front();
                q.pop();
                // 位置自增
                ++j;
                // words[i] 字符串匹配完成，
                if (j == words[i].size()) {
                    // 结果加 1
                    ++res;
                } else {
                    // 向队列中添加新的匹配项，words 中的第i 个字符串，下一次应该匹配的单词为words[i][j]
                    queues[words[i][j] - 'a'].emplace(i, j);
                }
            }
        }
        return res;
    }
};

/*

var numMatchingSubseq = function(s, words) {
    const p = new Array(26).fill(0).map(() => new Array());
    for (let i = 0; i < words.length; ++i) {
        p[words[i][0].charCodeAt() - 'a'.charCodeAt()].push([i, 0]);
    }
    let res = 0;
    for (let i = 0; i < s.length; ++i) {
        const c = s[i];
        let len = p[c.charCodeAt() - 'a'.charCodeAt()].length;
        while (len > 0) {
            const t = p[c.charCodeAt() - 'a'.charCodeAt()].shift();
            if (t[1] === words[t[0]].length - 1) {
                ++res;
            } else {
                ++t[1];
                p[words[t[0]][t[1]].charCodeAt() - 'a'.charCodeAt()].push(t);
            }
            --len;
        }
    }
    return res;
}


*/
