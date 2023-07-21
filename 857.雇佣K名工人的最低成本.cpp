#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
#include<algorithm>

// https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/submissions/

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> member(n, 0);
        iota(member.begin(), member.end(), 0);
        sort(member.begin(), member.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
            });

        double res = 1e9;
        double totalQuality = 0.0;
        priority_queue<int, vector<int>, less<int>> que;
        for (int i = 0; i < k - 1; i++) {
            totalQuality += quality[member[i]];
            que.push(quality[member[i]]);
        }
        for (int i = k - 1; i < n; i++) {
            int index = member[i];
            totalQuality += quality[index];
            que.push(quality[index]);
            double totalPaid = ((double)wage[index] / quality[index]) * totalQuality;
            res = min(res, totalPaid);
            totalQuality -= que.top();
            que.pop();
        }
        return res;
    }
};