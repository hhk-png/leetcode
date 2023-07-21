#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/* https://leetcode.cn/problems/brick-wall/

你的面前有一堵矩形的、由 n 行砖块组成的砖墙。
    这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和相等。

你现在要画一条 自顶向下 的、穿过 最少 砖块的垂线。
    如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。
    你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。

给你一个二维数组 wall ，该数组包含这堵墙的相关信息。
    其中，wall[i] 是一个代表从左至右每块砖的宽度的数组。
    你需要找出怎样画才能使这条线 穿过的砖块数量最少 ，
    并且返回 穿过的砖块数量 。

*/

class Solution {
public:
    // 砖块的高度减去缝隙的数量就是垂线所经过的砖块的数量，在砖块的累计宽度相等的地方就是出现缝隙的地方。
    //      因此砖块的高度减去最大缝隙数，就是垂线所经过砖块的最小数目
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& widths : wall) {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += widths[i];
                cnt[sum]++;
            }
        }

        int maxVal = 0;
        for (auto& [_, val] : cnt) {
            maxVal = max(maxVal, val);
        }

        return wall.size() - maxVal;
    }
};