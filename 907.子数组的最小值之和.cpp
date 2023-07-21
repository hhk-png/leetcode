#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。

由于答案可能很大，因此 返回答案模 10^9 + 7 。

 

示例 1：

输入：arr = [3,1,2,4]
输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
示例 2：

输入：arr = [11,81,94,43,3]
输出：444

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-subarray-minimums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
	const int BASE = 1e9 + 7;
public:
	int sumSubarrayMins(vector<int>& arr) {
		stack<int> stk;
		arr.push_back(0);               // 保证栈中所有元素都会被弹出计算
		int len = arr.size();
		long res = 0;
		for (int i = 0; i < len; ++i) {
			while (!stk.empty() && arr[i] <= arr[stk.top()]) {
				int index = stk.top(); stk.pop();
				int prev_index = -1;
				if (!stk.empty()) prev_index = stk.top();
				int prev_count = index - prev_index - 1; // 数量m
				int next_count = i - index - 1;          // 数量n
				res += long(arr[index]) * (prev_count + 1) * (next_count + 1) % BASE;
				res %= BASE;
			}
			stk.push(i);
		}
		return res;
	}
};