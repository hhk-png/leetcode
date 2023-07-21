#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*

将非负整数 num 转换为其对应的英文表示。

示例 1：
输入：num = 123
输出："One Hundred Twenty Three"

示例 2：
输入：num = 12345
输出："Twelve Thousand Three Hundred Forty Five"

示例 3：
输入：num = 1234567
输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

*/

class Solution {
public:
    vector<string> singles = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    vector<string> teens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    vector<string> tens = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    vector<string> thousands = { "", "Thousand", "Million", "Billion" };

    string numberToWords(int num) {
        // 如果是0，则直接返回Zero
        if (num == 0) {
            return "Zero";
        }
        // 存储最终结果
        string sb;
        // 1000000000 是int类型能保存的最大位数的数字
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            // 通过除以 uint 将数字分模块计算
            int curNum = num / unit;
            if (curNum != 0) {
                // 最高几位的数字
                num -= curNum * unit;
                // 当前字段的百十个位表示
                sb = sb + toEnglish(curNum) + thousands[i] + " ";
            }
        }
        // 清除最后的空格
        while (sb.back() == ' ') {
            sb.pop_back();
        }
        return sb;
    }

    // num 是三位数
    string toEnglish(int num) {
        string curr;
        // 百位数
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            curr = curr + singles[hundred] + " Hundred ";
        }
        // 十位数，大于等于 20
        int ten = num / 10;
        if (ten >= 2) {
            curr = curr + tens[ten] + " ";
            num %= 10;
        }
        // 个位数和大于十的数
        if (num > 0 && num < 10) {
            curr = curr + singles[num] + " ";
        }
        else if (num >= 10) {
            curr = curr + teens[num - 10] + " ";
        }
        return curr;
    }
};
