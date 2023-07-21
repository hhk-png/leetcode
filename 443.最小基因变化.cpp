#include<iostream>
#include<unordered_set>
#include<string>


/* https://leetcode.cn/problems/minimum-genetic-mutation/

基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

示例 1：

输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
输出：1
示例 2：

输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
输出：2
示例 3：

输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
输出：3

*/


using namespace std;

class Solution {
private:
    int minNum = INT_MAX;
    // 存储已经访问过的字符串，防止兜圈子
    unordered_set<string> set;
public:
    void dfs(int num, string start, string end, vector<string>& bank) {
        /* 递归截止条件 计算最小变化次数 */
        if (start == end) {
            minNum = min(num, minNum);
            return;
        }
        // 这里没有
        for (string& str : bank) {
            // 统计两个字符串中不相同的个数
            int diff = 0;
            // 直接从bank 里搜索下一个深度的字符串，只有当前字符串与bank 里面的字符串的字符相差一个的情况下才进入下一层
            for (int i = 0; i < str.size(); i++)
                if (str[i] != start[i]) diff++;

            if (diff == 1 && set.find(str) == set.end()) {
                // 回溯
                set.insert(str);
                dfs(num + 1, str, end, bank);
                set.erase(str); // 回溯，删除字符串
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        dfs(0, start, end, bank);
        return minNum == INT_MAX ? -1 : minNum;
    }
};