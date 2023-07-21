#include<iostream>
#include<vector>
#include<string>

using namespace std;


/* https://leetcode.cn/problems/permutation-in-string/

给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。

 

示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false

*/


// 滑动窗口
// 维持一个窗口大小为n 的滑动窗口，当cnt1 等于 cnt2 的时候返回true
class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (int i = 0; i < n; i++) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) {
            return true;
        }

        for (int i = n; i < m; i++) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) {
            return false;
        }

        // cnt 内的有效值默认小于 0，其他值默认等于0
        vector<int> cnt(26, 0);
        for (char c : s1) {
            --cnt[c - 'a'];
        }

        // 左指针
        int left = 0;
        for (int right = 0; right < m; right++) {
            int s2Char = s2[right] - 'a';
            ++cnt[s2Char];
            // 此处不可以为 ==0，
            //   cnt的其他值默认为0，当right 指向的字符不是s1 中的字符时，
            //   此条件也可能会成立，造成误判
            while (cnt[s2Char] > 0) {
                --cnt[s2[left] - 'a'];
                ++left;
            }
            // [left, right] 之间的距离为n 时，cnt中数字的总合也为 n
            if (right - left + 1 == n) {
                return true;
            }
        }

        return false;
    }
};
