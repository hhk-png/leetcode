﻿#include<iostream>
#include<vector>
#include<string>

using namespace std;

/* https://leetcode.cn/problems/string-compression/

给你一个字符数组 chars ，请使用下述算法压缩：

从一个空字符串 s 开始。对于 chars 中的每组 连续重复字符 ：

如果这一组长度为 1 ，则将字符追加到 s 中。
否则，需要向 s 追加字符，后跟这一组的长度。
压缩后得到的字符串 s 不应该直接返回 ，需要转储到字符数组 chars 中。需要注意的是，如果组长度为 10 或 10 以上，则在 chars 数组中会被拆分为多个字符。

请在 修改完输入数组后 ，返回该数组的新长度。

你必须设计并实现一个只使用常量额外空间的算法来解决此问题。

 

示例 1：

输入：chars = ["a","a","b","b","c","c","c"]
输出：返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]
解释："aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。
示例 2：

输入：chars = ["a"]
输出：返回 1 ，输入数组的前 1 个字符应该是：["a"]
解释：唯一的组是“a”，它保持未压缩，因为它是一个字符。
示例 3：

输入：chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
输出：返回 4 ，输入数组的前 4 个字符应该是：["a","b","1","2"]。
解释：由于字符 "a" 不重复，所以不会被压缩。"bbbbbbbbbbbb" 被 “b12” 替代。

*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, left = 0;
        // 用了三个指针，write用来写，left和right用来统计距离
        //  如果只是用left 和right 两个指针的话，那么left 既要负责写chars，又要与right 计算统计距离
        //  当面对多个和单个连续字符时就会很难处理，
        for (int read = 0; read < n; read++) {
            // read == n - 1 是考虑了chars最后只有一个重复单词的情况
            //  right 指向下一组相同字符串的前一个位置
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                // 复制字符
                chars[write++] = chars[read];
                int num = read - left + 1;

                // 复制数字
                // 只有一个字符的时候不需要在后面添加数字
                if (num > 1) {
                    for (auto c : to_string(num)) {
                        chars[write++] = c;
                    }
                }
                // left 指向下一组相同字符串
                left = read + 1;
            }
        }
        return write;
    }
};
