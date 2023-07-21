#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// https://leetcode.cn/problems/freedom-trail/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<int> pos[26];
        // �ַ� -> �ַ����ֵ�λ��
        for (int i = 0; i < n; ++i) {
            pos[ring[i] - 'a'].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
        // �����ַ����ĵ�����ַ�ƥ��
        for (auto& i : pos[key[0] - 'a']) {
            dp[0][i] = min(i, n - i) + 1;
        }
        // dp[i][j] ��ʾring[0:j] ƥ��key[0:i] ����Ҫ����̾���
        for (int i = 1; i < m; ++i) { // ����key
            // �����Ķ���pos�е�λ�ã�
            // pos[key[i] - 'a'] ��ʾ��key[i] ��ȵ�ring�еĸ����ַ���λ��
            for (auto& j : pos[key[i] - 'a']) { // ͨ��pos ����ring �е��ַ�λ��
                for (auto& k : pos[key[i - 1] - 'a']) { // ��Ҫ�õ���һ��״̬��������С�����ۼ�ֵ����Сֵ
                    // j - k ��ʾ��һ���ַ��뵱ǰ����ַ��ľ��롣
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};