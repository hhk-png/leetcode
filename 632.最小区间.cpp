#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/* https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/

你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

 

示例 1：

输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出：[20,24]
解释：
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
示例 2：

输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
输出：[1,1]

*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexes;
        // nums 中所有数字的最小值和最大值
        int xMin = INT_MAX;
        int xMax = INT_MIN;
        // 遍历nums 中所有的数字
        for (int i = 0; i < n; i++) {
            for (const int& num : nums[i]) {
                // 添加数字对应的索引，索引的大小范围为[0, n - 1]
                indexes[num].push_back(i);
                xMax = max(xMax, num);
                xMin = min(xMin, num);
            }
        }

        // 不添加n 的话不会初始化，不能直接对值进行操作
        vector<int> freq(n);
        // left 和 right 对应的是nums 中的数值
        //  
        int bestLeft = xMin;
        int bestRight = xMax;
        int left = xMin;
        int right = xMin - 1;
        // 处于窗口中的索引的个数，索引为nums 的索引
        int insides = 0;

        // [left, right]的范围会缩小，但这些值所对应的无重复索引的个数一直为 n，
        //  即为nums的大小，表示这个范围内包含了所有的nums中数组的数
        while (right < xMax) {
            right++;
            if (indexes.count(right)) {
                for (const int& index : indexes[right]) {
                    ++freq[index];
                    // freq[index] 刚等于1 时，进行窗口中索引值的增加
                    if (freq[index] == 1) {
                        insides++;
                    }
                }
                while (insides == n) {
                    // 得到一个更小的范围，
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indexes.count(left)) {
                        for (const int& index : indexes[left]) {
                            --freq[index];
                            if (freq[index] == 0) {
                                insides--;
                            }
                        }
                    }
                    left++;
                }
            }
        }

        return { bestLeft, bestRight };
    }
};
