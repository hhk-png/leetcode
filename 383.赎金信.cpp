#include<iostream>
#include<vector>
#include<string>

using namespace std;


/*

    ���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�

    ������ԣ����� true �����򷵻� false ��

    magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�

    https://leetcode.cn/problems/ransom-note/
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
        for (char m : magazine) {
            count[m - 'a']++;
        }
        for (char r : ransomNote) {
            int temp = r - 'a';
            count[temp]--;
            if (count[temp] < 0) {
                return false;
            }
        }
        
        return true;
    }
};

