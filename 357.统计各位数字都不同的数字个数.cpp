#include<iostream>

using namespace std;

// https://leetcode.cn/problems/count-numbers-with-unique-digits/submissions/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int cur = 9;
        int res = 10;
        for (int i = 0; i < n - 1; i++) {
            cur *= 9 - i;
            res += cur;
        }
        return res;
    }
};