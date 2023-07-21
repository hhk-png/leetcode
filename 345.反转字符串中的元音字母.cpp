#include<iostream>
#include<vector>
#include<string>

using namespace std;


/*

    给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

    元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。

    https://leetcode.cn/problems/reverse-vowels-of-a-string/
*/


class Solution {
public:
    string reverseVowels(string s) {

        auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
            return vowels.find(ch) != string::npos;
        }

        int n = size();
        int i = 0;
        int j = n - 1;
        while (i < n) {
            while (i < n && !isVowel(s[i])) {
                i++;
            }
            while (j > 0 && !isVowel(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--
            }
        }

        return s;
    }
};



