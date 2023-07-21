#include<iostream>
#include<string>
#include<vector>

using namespace std;


/*

    给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，
    并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。

    在执行上述操作后，返回包含相同字母的最长子字符串的长度。

 

    示例 1：
        输入：s = "ABAB", k = 2
        输出：4
        解释：用两个'A'替换为两个'B',反之亦然。

    示例 2：
        输入：s = "AABABBA", k = 1
        输出：4
        解释：
        将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
        子串 "BBBB" 有最长重复字母, 答案为 4。

*/


// 滑动窗口
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.size();
        vector<int> nums(26);
        // [left, right] 范围内与占比最多的字符的个数
        int maxn = 0;
        // [left, right] 是一个滑动窗口，
        //      right 每次向右移动一格，将遇到的字符记录到nums 中，并统计个数
        //      left 在其余字符的数量大于k 的时候，向右移动一个单位，并将因为移动抛弃掉的字符在nums中去除
        //      最终窗口会停在[left, right] 范围内能够使用k 将其余字符全部替换掉的时候，
        while (right < n) {
            // 右指针所指向的字符
            int rightIndex = s[right - 'A'];
            nums[rightIndex]++;
            maxn = max(maxn, nums[rightIndex]);
            if (right - left - maxn + 1 > k) {
                nums[s[left] - 'A']--;
                left++;
            }
            right++;
        }

        return right - left;
    }
};
