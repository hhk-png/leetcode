#include<iostream>
#include<vector>
#include<string>

using namespace std;

using ULL = unsigned long long;

// https://leetcode.cn/problems/find-the-closest-palindrome/

class Solution {
public:
    vector<ULL> getCandidates(const string& n) {
        int len = n.length();
        vector<ULL> candidates = {
            // 999...999
            (ULL)pow(10, len - 1) - 1,
            // 1000...0001
            (ULL)pow(10, len) + 1
        };
        // prefix
        ULL selfPrefix = stoull(n.substr(0, (len + 1) / 2));
        for (int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}) {
            string prefix = to_string(i);
            // join prefix and the second half of the number
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            candidates.push_back(stoull(candidate));
        }
        return candidates;
    }

    string nearestPalindromic(string n) {
        ULL selfNumber = stoull(n);
        ULL ans = -1;
        const vector<ULL>& candidates = getCandidates(n);
        for (auto& candidate : candidates) {
            if (candidate != selfNumber) {
                if (
                    ans == -1 ||
                    llabs(candidate - selfNumber) < llabs(ans - selfNumber) ||
                    llabs(candidate - selfNumber) == llabs(ans - selfNumber) && candidate < ans
                ) {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }
};

