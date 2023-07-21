#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

/*

给定一个字符串 s 表示一个整数嵌套列表，
    实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。

列表中的每个元素只可能是整数或整数嵌套列表

 

*/



// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};


// 栈
class Solution {
public:
    NestedInteger deserialize(string s) {
        // 如果开头是 '[' 说明s是存数字的字符串，将其转换为数字即可
        if (s[0] != '[') 
            return NestedInteger(stoi(s));

        // 用于表示嵌套
        stack<NestedInteger> stk;
        // 过程中数字字符的累加
        int num = 0;
        // 有复数
        bool negative = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '-') {
                negative = true;
            } else if (c == '[') { // 要开始一个嵌套
                stk.emplace(NestedInteger());
            } else if (isdigit(c)) { // 数字，与num累计
                num = num * 10 + c - '0';
            } else if (c == ',' || c == ']') { // 如果遇到 ‘]’ 或 ‘,’，则表示是一个数字或者 NestedInteger 实例的结束，
                                            // 需要将其添加入栈顶的 NestedInteger 实例。
                if (isdigit(s[i - 1])) { // 如果是数字，
                    if (negative) {
                        num = -num;
                    }
                    stk.top().add(NestedInteger(num)); // 则表示只要向当前的NestedInteger 中添加一个数字NestedInteger
                }
                negative = false; // 归零
                num = 0;
                // 如果stk 的大小不大于 1，则是NestedInteger 没有嵌套的情况，如果一直没有嵌套，
                //      最后直接将stk.top()返回就可以，
                if (c == ']' && stk.size() > 1) {
                    // 遇到 ‘]’ 则需要向上一层追加嵌套
                    NestedInteger ni = stk.top(); stk.pop();
                    stk.top().add(ni);
                }
            }

        }

        // 最终stk的大小为1
        return stk.top();
    }
};


// dfs
class Solution {
public:
    int index = 0;
    NestedInteger deserialize(string s) {
        if (s[index] == '[') {
            // 跳过 ‘[’
            index++;
            NestedInteger ni;
            while (s[index] != ']') {
                // 解析 ‘[]’ 里面的内容
                ni.add(deserialize(s));
                if (s[index] == ',') {
                    // 跳过 ‘,’
                    index++;
                }
            }
            // 跳过 ‘]’
            index++;
            // 返回当前构造的 NestedInteger
            return ni;
        } else { // 解析数字
            bool negative = false;
            int num = 0;
            
            // 符号
            if (s[index] == '-') {
                negative = true;
                index++;
            }

            // 数字大小
            while (index < s.size() && isdigit(s[index])) {
                num = num * 10 + s[index];
                index++;
            }

            // 改变数字的符号
            if (negative) {
                num = -num;
            }

            // 返回NestedInteger 包裹的数字
            return NestedInteger(num);
        }
    }
};


