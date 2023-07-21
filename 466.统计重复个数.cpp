#include<iostream>
#include<string>
#include<unordered_map>


/* https://leetcode.cn/problems/count-the-repetitions/

定义 str = [s, n] 表示 str 由 n 个字符串 s 连接构成。

例如，str == ["abc", 3] =="abcabcabc" 。
如果可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。

例如，根据定义，s1 = "abc" 可以从 s2 = "abdbec" 获得，仅需要删除加粗且用斜体标识的字符。
现在给你两个字符串 s1 和 s2 和两个整数 n1 和 n2 。由此构造得到两个字符串，其中 str1 = [s1, n1]、str2 = [s2, n2] 。

请你找出一个最大整数 m ，以满足 str = [str2, m] 可以从 str1 获得。

示例 1：
    输入：s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
    输出：2

示例 2：
    输入：s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
    输出：1

*/


using namespace std;
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }
        // s1cnt: 经过的 s1 的个数
        // s2cnt: 经过的 s2 的个数
        // index: 当前的s1 遍历完成时, s2 的字符停留在的位置
        int s1cnt = 0, index = 0, s2cnt = 0;

        // 存储的是当前的 {s2index, {s1cnt, s2cnt}}
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        // 寻找循环节
        while (true) {
            ++s1cnt;
            for (char ch : s1) {
                if (ch == s2[index]) {
                    index += 1;
                    if (index == s2.size()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }

            // 只有遇到循环节时才会出现遇到相同索引的情况
            if (recall.count(index)) {
                // 前 s1cnt_prime 个 s1 包含了 s2cnt_prime 个 s2
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                pre_loop = { s1cnt_prime, s2cnt_prime };
                // 以后的每 (s1cnt - s1cnt_prime) 个 s1 包含了 (s2cnt - s2cnt_prime) 个 s2
                in_loop = { s1cnt - s1cnt_prime, s2cnt - s2cnt_prime };
                break;
            } else {
                recall[index] = { s1cnt, s2cnt };
            }
        }

        // 统计需要的 s2 的个数
        // (n1 - pre_loop.first) / in_loop.first: 剩余的循环节的个数
        // in_loop.second: s2cnt - s2cnt_prime , 每个循环节包含 s2 字符串的个数
        int ans = pre_loop.second + ((n1 - pre_loop.first) / in_loop.first) * in_loop.second;
        // 剩余的 s1 字符串个数
        int rest = (n1 - pre_loop.first) % in_loop.first;
        // 每一次循环进行一次 s1 字符串的遍历
        for (int i = 0; i < rest; ++i) {
            for (char ch : s1) {
                // 若遇到s1 与s2 相同的字符, 则s2 的index前进一个
                if (ch == s2[index]) {
                    ++index;
                    // 如果 s2 遍历完成, 则表示一个s1 的循环节遍历完成
                    if (index == s2.size()) {
                        ++ans;
                        index = 0;
                    }
                }
            }
        }

        // 需要多少个 [s2, n2] 字符串
        return ans / n2;
    }
};