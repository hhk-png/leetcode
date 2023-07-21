#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;


/*

你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：

猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。

提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。

示例 1：

    输入：secret = "1807", guess = "7810"
    输出："1A3B"
    解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
    "1807"
      |
    "7810"

示例 2：
    输入：secret = "1123", guess = "0111"
    输出："1A1B"
    解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
    "1123"        "1123"
      |      or     |
    "0111"        "0111"
    注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。


*/


class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        unordered_map<char, int> hash;
        for (int i = 0; i < secret.size(); i++) {
            char secretVal = secret[i];
            hash[secretVal]++;
            bull += (secretVal == guess[i]);
        }
        for (char& gchar : guess) {
            cow += (hash[gchar]-- > 0);
        }
        cow -= bull;
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        unordered_map<char, int> hash;
        // 先将 bull 统计出来，并在此过程中对secret与guess相同位置上不相同的字符创建一个表示个数的hash，hash根据secret创建
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bull++;
            else
                hash[secret[i]]++;
        }

        // 统计 cow，只对同位置不同字符的情况进行处理
        //   
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i]) {
                // hash[guess[i]] 不为0 表示secret中还存在guess[i]字符，可以通过调换位置使两个字符串的相似度增加一个字符
                //   对其 “--” 是考虑了重复字符的情况
                cow += (hash[guess[i]]-- > 0);
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};


class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            }
            else {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            // 由于多余的数字无法匹配，对于 0 到 9 的每位数字，应取其在 secret 和 guess 中的出现次数的最小值。
            //   将每位数字出现次数的最小值累加，即为奶牛的个数。
            cows += min(cntS[i], cntG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};


