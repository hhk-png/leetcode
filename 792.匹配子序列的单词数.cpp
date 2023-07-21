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
        // pair<int, int>: �ַ���words[i] Ŀǰƥ�䵽�˵� j ��λ�ã���λ�õ���ĸΪ i + 'a'
        for (int i = 0; i < words.size(); ++i) {
            queues[words[i][0] - 'a'].emplace(i, 0);
        }
        int res = 0;
        for (char c : s) {
            // ����ĸc ��ͷ��queue
            auto& q = queues[c - 'a'];
            // �Զ��������е�ƥ�����������
            int size = q.size();
            while (size--) {
                // ȡ����ͷԪ�أ�
                //  i: �ַ�����words �е�����
                //  j: �ַ����Ѿ�ƥ�䵽�˵� j ��λ�ã�����ƥ����ĸc����ƥ������ 
                auto [i, j] = q.front();
                q.pop();
                // λ������
                ++j;
                // words[i] �ַ���ƥ����ɣ�
                if (j == words[i].size()) {
                    // ����� 1
                    ++res;
                } else {
                    // �����������µ�ƥ���words �еĵ�i ���ַ�������һ��Ӧ��ƥ��ĵ���Ϊwords[i][j]
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
