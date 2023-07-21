#include<iostream>
#include<vector>
#include<string>
#include<queue>

// https://leetcode.cn/problems/reorganize-string/submissions/

using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        if (n < 2) return s;
        int maxCount = 0;
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            count[c - 'a']++;
            maxCount = max(maxCount, count[c - 'a']);
        }

        if (maxCount > (n + 1) / 2) return "";
        auto cmp = [&](const char& letter1, const char& letter2) {
            return count[letter1 - 'a'] < count[letter2 - 'a'];
        };


        priority_queue<char, vector<char>, decltype(cmp)> queue{ cmp };

        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c - 'a'] > 0) {
                queue.push(c);
            }
        }

        string result = "";
        while (queue.size() > 1) {
            char letter1 = queue.top(); queue.pop();
            char letter2 = queue.top(); queue.pop();
            result += letter1;
            result += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            count[index1]--;
            count[index2]--;
            if (count[index1] > 0) {
                queue.push(letter1);
            }
            if (count[index2] > 0) {
                queue.push(letter2);
            }
        }

        if (queue.size() > 0) {
            result += queue.top();
        }

        return result;
    }
};