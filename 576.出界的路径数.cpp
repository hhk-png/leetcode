#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/out-of-boundary-paths/

class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int res = 0;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
        dp[0][startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    int count = dp[i][j][k];
                    if (count > 0) {
                        for (auto& direction : directions) {
                            int j1 = j + direction[0];
                            int k1 = k + direction[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {
                                dp[i + 1][j1][k1] = (dp[i + 1][j1][k1] + count) % MOD;
                            }
                            else {
                                res = (res + count) % MOD;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
