#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

// https://leetcode.cn/problems/matchsticks-to-square/

class Solution {
public:
    bool dfs(vector<int>& matchsticks, int index, vector<int>& edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int edge = edges[i];
            int matchstick = matchsticks[index];
            // 若上一条边没有成功，则当前边一定不会成功。
            if (edge + matchstick > len || (i > 0 && edges[i - 1] == edge)) {
                continue;
            }
            edges[i] += matchstick;
            if (edge <= len && dfs(matchsticks, index + 1, edges, len)) {
                return true;
            }
            edges[i] -= matchstick;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        int len = totalLen / 4;
        if (matchsticks[matchsticks.size() - 1] > len) {
            return false;
        }
        vector<int> edges(4);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, 0, edges, len);
    }
};

