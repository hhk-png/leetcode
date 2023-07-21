#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

/*

给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，
    使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

 
示例 1 ：
    输入：num = "1432219", k = 3
    输出："1219"
    解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。

示例 2 ：
    输入：num = "10200", k = 1
    输出："200"
    解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

示例 3 ：
    输入：num = "10", k = 2
    输出："0"
    解释：从原数字移除所有的数字，剩余为空就是 0 。


*/

class Solution {
public:
    // 贪心 + 单调栈
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit : num) { // 遍历 num
            // 当遇到stk[i-1] > stk[i]的时候，将stk中所有大于digit，也就是stk[i]的值全部删掉，并将digit入栈，
            //      删掉的值相当于移除掉num中对应的数，使k - 1
            while (stk.size() > 0 && stk.back() > digit && k) {
                stk.pop_back();
                k--;
            }
            stk.push_back(digit);
        }

        // k 的值还没到0，表示还没有将要删除字符的余量用完，因为stk是单调增的，所以将剩余的最大k个值删去
        while (k > 0) {
            stk.pop_back();
            k--;
        }

        // result
        string result;
        // 是否是首个字符
        bool isLeading = true;
        for (char& digit : stk) {
            // 如果首个字符为 '0'
            if (isLeading && digit == '0') {
                // 则屏蔽掉
                continue;
            }
            // isLeading 只起作用一次
            isLeading = false;
            result += digit;
        }

        return result == "" ? "0" : result;
    }
};





