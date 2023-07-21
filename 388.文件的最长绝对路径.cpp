#include<iostream>
#include<vector>
#include<string>

using namespace std;

/* https://leetcode.cn/problems/longest-absolute-file-path/ */
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        // 记录累加的文件目录长度，通过len 累加
        vector<int> level(n + 1);

        // 输入文件目录字符串的每一行可以以“\t 文件或文件夹名称 \n” 这种表示，按照这种表示来分析
        //   每一次循环 level 都会重新从 1 开始计数
        while (pos < n) {
            // 通过 \t 的个数来计算出文件目录的深度
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++; // 前进一个字符
                depth++; // 深度加 1
            }

            // 计算文件或文件夹名称的长度
            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                // 若遇到 “.” 则表示是文件名
                if (input[pos] == '.') {
                    isFile = true;
                }
                // 名称长度+1
                len++;
                // 位置前进一位
                pos++;
            }
            // 跳过换行符 \n 
            pos++; // 进入下一行

            // 长度累加
            if (depth > 1) {
                len += level[depth - 1] + 1;
            }

            // 如果是文件，则统计最大值
            if (isFile) {
                ans = max(len, ans);
            }
            else {
                // 否则将长度计入level中
                level[depth] = len;
            }

        }
        return ans;
    }
};

