#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

// https://leetcode.cn/problems/tag-validator/

class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> tags;

        int i = 0;
        while (i < n) {
            // 遇到 < 再进行处理
            if (code[i] == '<') {
                if (i == n - 1) {
                    return false;
                }
                // 结束标签
                if (code[i + 1] == '/') {
                    // 找不到结束符号，返回false
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    // 获取结束标签的 tagname
                    string tagName = code.substr(i + 2, j - (i + 2));
                    // 之前的tags 为空或者标签不匹配
                    if (tags.empty() || tags.top() != tagName) {
                        return false;
                    }
                    tags.pop();
                    // 移动i 的位置
                    i = j + 1;
                    // 遍历还没有结束，tags就为空，返回false
                    if (tags.empty() && i != n) {
                        return false;
                    }
                // cdata
                } else if (code[i + 1] == '!') {
                    // 表示cdata 没有被标签包裹
                    if (tags.empty()) {
                        return false;
                    }
                    // 获取cdata 标签
                    string cdata = code.substr(i + 2, 7);
                    if (cdata != "[CDATA[") {
                        return false;
                    }
                    // 寻找cdata content 后的结束符号
                    int j = code.find("]]>", i);
                    if (j == string::npos) {
                        return false;
                    }
                    // 移动i 的位置
                    i = j + 3;
                // 开始标签
                } else {
                    // 开始标签不需要监测tags 是否为空
                    // 找不到开始标签的结束符号，
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    // tagname
                    string tagName = code.substr(i + 1, j - (i + 1));
                    if (tagName.size() < 1 || tagName.size() > 9) {
                        return false;
                    }
                    // tagname 需全部为大写字母
                    if (!all_of(tagName.begin(), tagName.end(), [](unsigned char c) {return isupper(c);})) {
                        return false;
                    }

                    tags.push(move(tagName));
                    // 移动i 的位置
                    i = j + 1;
                }
            } else {
                // 
                if (tags.empty()) {
                    return false;
                }
                ++i;
            }
        }

        // 最终tags 不为空，此标签字符串才是合法的
        return tags.empty();
    }
};


