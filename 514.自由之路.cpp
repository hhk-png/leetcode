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
        // 字符 -> 字符出现的位置
        for (int i = 0; i < n; ++i) {
            pos[ring[i] - 'a'].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
        // 两个字符串的第零个字符匹配
        for (auto& i : pos[key[0] - 'a']) {
            dp[0][i] = min(i, n - i) + 1;
        }
        // dp[i][j] 表示ring[0:j] 匹配key[0:i] 所需要的最短距离
        for (int i = 1; i < m; ++i) { // 遍历key
            // 遍历的都是pos中的位置，
            // pos[key[i] - 'a'] 表示与key[i] 相等的ring中的各个字符的位置
            for (auto& j : pos[key[i] - 'a']) { // 通过pos 遍历ring 中的字符位置
                for (auto& k : pos[key[i - 1] - 'a']) { // 需要用到上一个状态来计算最小距离累计值的最小值
                    // j - k 表示上一个字符与当前相等字符的距离。
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};