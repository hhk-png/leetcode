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
            // 如果找到了 x - 1，则弹出 x - 1 的队列头部，加入x元素
            if (mp.find(x - 1) != mp.end()) {
                // mp[x - 1].top() 存储的是
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

