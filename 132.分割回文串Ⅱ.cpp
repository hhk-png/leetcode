#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。


示例 1：
    输入：s = "aab"
    输出：1
    解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

示例 2：
    输入：s = "a"
    输出：0

示例 3：
    输入：s = "ab"
    输出：1

*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        // 二维数组右上角
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                // 字符串 [i, j] 范围内的字符串是否是回文
                //  [i + 1, j - 1] 范围内的字符是回文，并且 i 和 j 位置上的字符相同
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }

        vector<int> res(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            // [0, i] 范围内的字符串是回文串，不需要分割
            if (dp[0][i]) {
                res[i] = 0;
            }
            // 需要分割
            else {
                // [1 2... , i] 范围内的字符串是回文串
                for (int j = 0; j < i; ++j) {
                    // 如果[1, j + 1]范围内的字符串都不是回文串，就会一直累加上去
                    if (dp[j + 1][i]) {
                        res[i] = min(res[i], res[j] + 1);
                    }
                }
            }
        }

        return res[n - 1];
    }
};