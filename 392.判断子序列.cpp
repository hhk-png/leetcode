#include<iostream>
#include<string>

using namespace std;

/*
* 
* https://leetcode.cn/problems/is-subsequence/

�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�

�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���

���ף�

����д�������� S������ S1, S2, ... , Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿


*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = 0;
        int sLen = s.size();

        while (left < sLen && right < t.size()) {
            if (s[left] == t[right]) {
                left++;
            }
            right++;
        }
        return left == sLen;
    }
};