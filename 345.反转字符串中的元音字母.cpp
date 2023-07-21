#include<iostream>
#include<vector>
#include<string>

using namespace std;


/*

    ����һ���ַ��� s ������ת�ַ����е�����Ԫ����ĸ�������ؽ���ַ�����

    Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'���ҿ����Դ�Сд������ʽ���֡�

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



