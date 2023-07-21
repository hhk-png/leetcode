#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

// https://leetcode.cn/problems/bus-routes/

using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // �������յ㣬���� 0
        if (source == target) return 0;

        // ��վ������
        int n = routes.size();
        // ��������������������ͼ
        vector<vector<int>> edge(n, vector<int>(n));
        // ��վ����������ӳ�䣬��վ�����ж������������
        unordered_map<int, vector<int>> siteToBus;
        // �������еĳ�վ��i Ϊ��վ�����Ĺ�����
        for (int i = 0; i < n; i++) {
            for (int site : routes[i]) {
                // �����ó�վ�������Ĺ�����
                for (int j : siteToBus[site]) {
                    // ���ù���������������·��
                    edge[i][j] = edge[j][i] = 1;
                }
                // ��Թ�������ӳ������� i
                //  site => i(bus)
                siteToBus[site].push_back(i);
            }
        }

        // ��Ҫ���˵Ĺ�����������
        vector<int> dis(n, -1);
        queue<int> que;
        // ��ʼ��վ�������Ĺ�����
        for (int site : siteToBus[source]) {
            // ����һ�ι�����
            dis[site] = 1;
            que.push(site);
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            // �������еĹ�����·�ߣ�Ҳ��������
            for (int y = 0; y < n; y++) {
                // ���Ի��ˣ�����û������y ������
                if (edge[x][y] && dis[y] == -1) {
                    // ����� 1
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }

        int result = INT_MAX;
        // ���������յ�վ�Ĺ�����
        for (int site : siteToBus[target]) {
            // ���Ե���
            if (dis[site] != -1) {
                result = min(result, dis[site]);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};