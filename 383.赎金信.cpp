#include<iostream>
#include<vector>
#include<string>

using namespace std;


/*

    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

    如果可以，返回 true ；否则返回 false 。

    magazine 中的每个字符只能在 ransomNote 中使用一次。

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

