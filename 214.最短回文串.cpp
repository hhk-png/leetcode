#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/*

给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

 
示例 1：
输入：s = "aacecaaa"
输出："aaacecaaa"

示例 2：
输入：s = "abcd"
输出："dcbabcd"

*/

// 找到字符串 s 的最长回文前缀，将剩余的字符串反转后拼接到最前方
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int left = 0,
            right = 0,
            mul = 1;
        int base = 131,
            mod = 1000000007;
        // 最佳位置
        int best = -1;
        for (int i = 0; i < n; i++) {
            // 正向 hash 值累加成一个 base 进制的数
            //  left * base + s[i];
            left = ((long long)left * base + s[i]) % mod;
            // 反向累加，right + base * s[i]
            right = (right + (long long)mul * s[i]) % mod;
            // 如果正反两个方向 hash 值相同
            if (left == right) {
                best = i;
            }
            // 反向累加 mul
            mul = (long long)mul * base % mod;
        }

        // 裁剪字符串
        string add = (best == n - 1) ? "" : s.substr(best + 1, n);
        // 翻转，拼接
        reverse(add.begin(), add.end());
        return add + s;
    }
};
