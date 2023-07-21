#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。

*/

class Solution {
private:
    string s1, s2, s3;
    vector<vector<bool>> visited;
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 保存字符
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        // s1 的长度加上 s2 的长度要等于 s3 的长度
        if (s1.length() + s2.length() != s3.length())
            return false;
        // 重新分配内存
        visited.resize(s1.length() + 1, vector<bool>(s2.length() + 1));
        return canMatch(0, 0, 0);
    }

    bool canMatch(int p1, int p2, int p3) {
        // p3 已经到了尽头，说明满足了要求
        if (p3 == s3.length())
            return true;
        // 已经访问过了，就不需要再继续访问下去，这条路线已经有了结果
        if (visited[p1][p2])
            return false;
        // 置访问标志
        visited[p1][p2] = true;
        // 匹配 s1
        if (p1 < s1.length() && s1[p1] == s3[p3] && canMatch(p1 + 1, p2, p3 + 1))
            return true;
        // 匹配 s2
        if (p2 < s2.length() && s2[p2] == s3[p3] && canMatch(p1, p2 + 1, p3 + 1))
            return true;
        // 最终未匹配成功
        return false;
    }
};



/* https://leetcode-cn.com/problems/interleaving-string/solution/jiao-cuo-zi-fu-chuan-by-leetcode-solution/ */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> f(s1.size() + 1, vector<bool>(s2.size() + 1));
        int m = s1.size(),
            n = s2.size(),
            l = s3.size();
        if (m + n != l)
            return false;

        f[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m][n];
    }
};