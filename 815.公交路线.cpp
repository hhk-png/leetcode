#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

// https://leetcode.cn/problems/bus-routes/

using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // 起点等于终点，返回 0
        if (source == target) return 0;

        // 车站的数量
        int n = routes.size();
        // 公交车到公交车的无向图
        vector<vector<int>> edge(n, vector<int>(n));
        // 车站到公交车的映射，车站可能有多个公交车经过
        unordered_map<int, vector<int>> siteToBus;
        // 遍历所有的车站，i 为车站经过的公交车
        for (int i = 0; i < n; i++) {
            for (int site : routes[i]) {
                // 遍历该车站所经过的公交车
                for (int j : siteToBus[site]) {
                    // 设置公交车到公交车的路线
                    edge[i][j] = edge[j][i] = 1;
                }
                // 向对公交车的映射中添加 i
                //  site => i(bus)
                siteToBus[site].push_back(i);
            }
        }

        // 所要换乘的公交车的数量
        vector<int> dis(n, -1);
        queue<int> que;
        // 初始车站所经过的公交车
        for (int site : siteToBus[source]) {
            // 换成一次公交车
            dis[site] = 1;
            que.push(site);
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            // 遍历所有的公交车路线，也即公交车
            for (int y = 0; y < n; y++) {
                // 可以换乘，并且没有做过y 公交车
                if (edge[x][y] && dis[y] == -1) {
                    // 距离加 1
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }

        int result = INT_MAX;
        // 遍历经过终点站的公交车
        for (int site : siteToBus[target]) {
            // 可以到达
            if (dis[site] != -1) {
                result = min(result, dis[site]);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};