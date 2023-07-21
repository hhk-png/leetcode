#include<iostream>
#include<string>
#include<deque>
using namespace std;

/*

给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
    返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

*/

class Solution {
public:
    string reverseWords(string s) {
        // 左指针，指向字符串的第一个字符
        int left = 0;
        // 右指针，指向字符串的最后一个字符
        int right = s.length() - 1;
        
        // 屏蔽掉前面的空格
        while (left <= right && s[left] == ' ') left++;
        // 屏蔽掉最后面的空格
        while (left <= right && s[right] == ' ') right--;

        // 双端队列，只用到了前面的出入口
        deque<string> d;
        // 存储单个单词
        string word = "";
        while (left <= right) {
            char c = s[left];
            // 当遇到空格的时候，并且word是一个单词的时候
            //   防止两个单词之间出现多个空格
            if (c == ' ' && word.size()) {
                // 向头部插入，最后从头部取出，栈结构
                //      用栈栈结构也是一样的
                d.push_front(word);
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            left++;
        }
        // 因为是遇到空格时才将单词放入到队列中，所以最后一个单词没有放入队列
        d.push_front(word);

        // 最终结果
        string res = "";
        while (!d.empty()) {
            // 依此从队列中取出单词，进行拼接
            res += d.front();
            d.pop_front();
            // 如果不是最后一个单词，就拼上一个空格
            if (!d.empty()) res += ' ';
        }
        return res;
    }
};
