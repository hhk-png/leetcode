#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*  https://leetcode.cn/problems/ones-and-zeroes/

给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：
    输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
    输出：4
    解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
    其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：
    输入：strs = ["10", "0", "1"], m = 1, n = 1
    输出：2
    解释：最大的子集是 {"0", "1"} ，所以答案是 2 。

*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
     
        // dp[i][j] : 使用i 个0 和j 个 1能覆盖的最大字符数
        for (auto& str : strs) {
            // str 中0 和1 的个数
            int c0 = find(str.begin(), str.end(), '0'),
                c1 = str.size() - c0;
            for (int j = m; j >= c0; --j) {
                for (int i = n; i >= c1; --i) {
                    dp[j][k] = max(dp[j][k], dp[j - c0][k - c1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
