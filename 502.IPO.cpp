#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

// https://leetcode.cn/problems/ipo/

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({ capital[i], profits[i] });
        }
        sort(arr.begin(), arr.end());
        int curr = 0;
        // 选择当前可以选择的最好的选项
        //  在该题目下，就是在资本合适的前提下，选择利润最大的项目
        while (k > 0) {
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
                k--;
            } else {
                break;
            }
        }
        return w;
    }
};

