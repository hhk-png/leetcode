#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

/*

给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

 
示例 1：
    输入：expression = "2-1-1"
    输出：[0,2]
    解释：
    ((2-1)-1) = 0
    (2-(1-1)) = 2

示例 2：
    输入：expression = "2*3-4*5"
    输出：[-34,-14,-10,-10,10]
    解释：
    (2*(3-(4*5))) = -34
    ((2*3)-(4*5)) = -14
    ((2*(3-4))*5) = -10
    (2*((3-4)*5)) = -10
    (((2*3)-4)*5) = 10

*/

class Solution {
public:
    vector<int> diffWaysToCompute(string& expression) {
        // 存储此次递归的结果
        vector<int> result;
        int n = expression.size();
        if (n == 1 || n == 2) {
            result.push_back(stoi(expression));
            return result;
        }

        // 遍历当前段的字符串，
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            // 如果是运算符
            if (c == '+' || c == '-' || c == '*') {
                // 计算运算符左边的所有数值
                vector<int> resultLeft = diffWaysToCompute(expression.substr(0, i));
                // 计算运算符右边的所有数值
                vector<int> resultRight = diffWaysToCompute(expression.substr(i + 1));
                // 计算 l * r 次
                //  分别遍历所有边的所有数
                for (int l : resultLeft) {
                    for (int r : resultRight) {
                        switch (c) {
                        case '+':
                            result.push_back(l + r);
                            break;
                        case '-':
                            result.push_back(l - r);
                            break;
                        case: '*' :
                            result.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }

        return result;
    }
};



