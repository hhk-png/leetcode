#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

/*
给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回 所有 能够得到 target 的表达式。

注意，返回表达式中的操作数 不应该 包含前导零。


示例 1:
    输入: num = "123", target = 6
    输出: ["1+2+3", "1*2*3"]
    解释: “1*2*3” 和 “1+2+3” 的值都是6。

示例 2:
    输入: num = "232", target = 8
    输出: ["2*3+2", "2+3*2"]
    解释: “2*3+2” 和 “2+3*2” 的值都是8。

示例 3:
    输入: num = "3456237490", target = 9191
    输出: []
    解释: 表达式 “3456237490” 无法得到 9191 。
*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        vector<string> ans;

        // 函数式写法
        function<void(string&, int, long, long)> backtrack = [&](string& expr, int index, long res, long mul) {
            // 到达了最后
            if (index == n) {
                // 并且结果正确
                if (res == target) {
                    // 将表达式放入最终结果
                    ans.emplace_back(expr);
                }
                // 否则这是一个无效的表达式
                return;
            }
            // 符号的位置
            int signIndex = expr.size();
            // 占位，符号位
            if (index > 0) {
                expr.push_back(0);
            }
            // 本次回溯的中间结果
            long val = 0;
            for (int j = index; (j < n) && (j == index || num[index] != '0'); j++) {
                // 累计数值，数字表达
                val = val * 10 + num[j] - '0';
                // push到字符串中
                expr.push_back(num[j]);
                // 表达式开头不能添加符号
                if (index == 0) {
                    backtrack(expr, j + 1, val, val);
                }
                else { // 枚举符号
                    expr[signIndex] = '+'; backtrack(expr, j + 1, res + val, +val);
                    expr[signIndex] = '-'; backtrack(expr, j + 1, res - val, -val);
                    // 乘号的优先级高于 + 和 -
                    expr[signIndex] = '*'; backtrack(expr, j + 1, res - mul + mul * val, mul * val);
                }
            }
            // 回溯，传递的是引用
            expr.resize(signIndex);
        };

        string expr;
        backtrack(expr, 0, 0, 0);
        return ans;
    }
};
