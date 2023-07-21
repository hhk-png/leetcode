
// https://leetcode.cn/problems/find-the-difference/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch : s + t) {
            // “ÏªÚ
            ret ^= ch;
        }
        return ret;
    }
};
