#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

 
示例 1：
    输入：s = "25525511135"
    输出：["255.255.11.135","255.255.111.35"]

示例 2：
    输入：s = "0000"
    输出：["0.0.0.0"]

示例 3：
    输入：s = "101023"
    输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


*/

class Solution {
private:
    static constexpr int SET_COUNT = 4;
public:
    vector<string> res;
    vector<int> segments;

    void dfs(string& s, int segId, int segStart) {
        if (segId == SET_COUNT) { // segID到达4，
            if (segStart == s.length()) { // 并且遍历到了字符串末尾
                // 拼接前面收集到的IP地址
                string IP = "";
                for (int i = 0; i < SET_COUNT; i++) {
                    // 
                    IP += to_string(segments[i]);
                    // 最后一段IP地址后面不需要带 "."
                    if (i != SET_COUNT - 1) {
                        IP += '.';
                    }
                }
                // 存放结果
                res.push_back(move(IP));
            }
            return;
        }

        // 已经到了最后，但ID还没有达到4，则此次dfs无效
        if (segStart == s.length()) {
            return;
        }

        // 因为不能有前导0，如果当前字符为0，则此段IP地址只能为0
        if (s[segStart] == '0') {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // 合格的 IPv4 地址：四个整数的范围都在 0~255 之间

        int addr = 0;
        // 通过 IP 地址的合法性来决定是否退出循环，
        //  只要有某一个整数不合法，则剩余字符全部无效
        for (int i = segStart; i < s.size(); i++) {
            // 拼接整数，
            addr = addr * 10 + (s[i] - '0');
            // IP地址合格验证
            if (addr > 0 && addr <= 0xFF) {
                // 通过 segID 将 IP 地址放到 segments 中，而不是通过 push_back
                //  不用回溯，因为要求的是将字符串分割为IP地址
                segments[segId] = addr;
                dfs(s, segId + 1, i + 1);
            }
            else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        // 重新分配内存
        segments.resize(SET_COUNT);
        dfs(s, 0, 0);
        return res;
    }
};

