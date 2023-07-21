#include<iostream>
#include<vector>
#include<string>

/* https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。

特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。

 s 的 子序列可以通过删去字符串 s 中的某些字符实现。

例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc" 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。

示例 1：
    输入: strs = ["aba","cdc","eae"]
    输出: 3

示例 2:
    输入: strs = ["aaa","aaa","aa"]
    输出: -1

*/

using namespace std;

class Solution {
public:
    bool isSubStr(string& original, string& target) {
        int left = 0;
        int right = 0;
        while (left < original.size() && right < target.size()) {
            if (original[left] == target[right]) {
                right++;
            }
            left++;
        }
        return right == target.size();
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int result = -1;
        for (int i = 0; i < n; i++) {
            bool check = true;
            for (int j = 0; j < n; j++) {
                // 检查strs[i] 是否是strs[j] 的子字符串
                if (i != j && isSubStr(strs[j], strs[i])) {
                    check = false;
                    break;
                }
            }
            // strs[i] 不是strs[j] 的子字符串，统计字符串的最大长度
            if (check) {
                result = max(result, strs[i].size());
            }
        }
        return result;
    }
};


