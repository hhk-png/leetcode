#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

/*

给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。

示例 1：
    输入：n = 10
    输出：12
    解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。

示例 2：
    输入：n = 1
    输出：1
    解释：1 通常被视为丑数。

*/

// 堆
class Solution2 {
public:
    int nthUglyNumber(int n) {
        // 1 是丑数，将1 乘以2，3，5之后得到的也是丑数，将这些结果依此再乘以2，3，5得到的也是丑数
        //  将这些结果放到最小堆中，递增取出最小值，得到第n 个丑数
        //  seen 记忆化
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        vector<long> factors{ 2, 3, 5 };
        seen.insert(1L);
        heap.push(1L);
        long ugly;
        for (int i = 0; i < n; i++) {
            long ugly = heap.top();
            heap.pop();
            for (long num : factors) {
                long curr = ugly * num;
                if (!seen.count(curr)) {
                    heap.push(curr);
                    seen.insert(curr);
                }
            }
        }

        return (int)ugly;
    }
};

// 动态规划
class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<long> dp(n);
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int num1 = dp[p1] * 2;
            int num2 = dp[p2] * 3;
            int num3 = dp[p3] * 5;
            int num = min(num1, min(num2, num3));
            dp[i] = num;
            if (num == num1) {
                p1++;
            }
            if (num == num2) {
                p2++;
            }
            if (num == num3) {
                p3++;
            }
        }

        return dp[n - 1];
    }
};

