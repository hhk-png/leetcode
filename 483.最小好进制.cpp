#include<iostream>
#include<vector>
#include<string>

using namespace std;

// https://leetcode.cn/problems/smallest-good-base/submissions/

class Solution {
public:
    string smallestGoodBase(string n) {
        long nVal = stol(n);
        int mMax = floor(log(nVal) / log(2));
        for (int m = mMax; m > 1; m--) {
            int k = pow(nVal, 1.0 / m);
            long mul = 1;
            long sum = 1;
            for (int i = 0; i < m; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == nVal) {
                return to_string();
            }
        }
        return to_string(nVal - 1);
    }
};
