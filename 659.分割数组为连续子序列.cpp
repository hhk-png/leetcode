#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

// https://leetcode.cn/problems/split-array-into-consecutive-subsequences/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        for (int x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>, greater<int>>();
            }
            // ����ҵ��� x - 1���򵯳� x - 1 �Ķ���ͷ��������xԪ��
            if (mp.find(x - 1) != mp.end()) {
                // mp[x - 1].top() �洢����
                int prevLen = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLen + 1);
            } else {
                mp[x].push(1);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            priority_queue<int, vector<int>, greater<int>> que = it->second;
            if (que.top() < 3) {
                return false;
            }
        }

        return true;
    }
};

