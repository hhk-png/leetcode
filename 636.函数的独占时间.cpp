﻿#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
	给出一个非抢占单线程CPU的 n 个函数运行日志，找到函数的独占时间。

	每个函数都有一个唯一的 Id，从 0 到 n-1，函数可能会递归调用或者被其他函数调用。

	日志是具有以下格式的字符串：function_id：start_or_end：timestamp。例如："0:start:0" 表示函数 0 从 0 时刻开始运行。"0:end:0" 表示函数 0 在 0 时刻结束。

	函数的独占时间定义是在该方法中花费的时间，调用其他函数花费的时间不算该函数的独占时间。你需要根据函数的 Id 有序地返回每个函数的独占时间。

	示例 1:
	输入:
		n = 2
		logs =
		["0:start:0",
		 "1:start:2",
		 "1:end:5",
		 "0:end:6"]
	输出:[3, 4]
	说明：
		函数 0 在时刻 0 开始，在执行了  2个时间单位结束于时刻 1。
		现在函数 0 调用函数 1，函数 1 在时刻 2 开始，执行 4 个时间单位后结束于时刻 5。
		函数 0 再次在时刻 6 开始执行，并在时刻 6 结束运行，从而执行了 1 个时间单位。
		所以函数 0 总共的执行了 2 +1 =3 个时间单位，函数 1 总共执行了 4 个时间单位。
	说明：

		输入的日志会根据时间戳排序，而不是根据日志Id排序。
		你的输出会根据函数Id排序，也就意味着你的输出数组中序号为 0 的元素相当于函数 0 的执行时间。
		两个函数不会在同时开始或结束。
		函数允许被递归调用，直到运行结束。
		1 <= n <= 100

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/exclusive-time-of-functions
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// stoi 将字符转换为正整数

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		// 最终结果，id -> 独占时间
		vector<int> result(n, 0);
		stack<pair<int, int>> stk;
		for (string& log : logs) {
			// 第一个:的位置
			int pos1 = log.find(':');
			// 后一个:的位置
			int pos2 = log.rfind(':');
			// 当前函数id
			int currentId = stoi(log.substr(0, pos1));
			// 当前正在执行的函数的状态，start或者end
			string currentAction = log.substr(pos1 + 1, pos2 - pos1 - 1);
			// 开始时间或者结束时间
			int currentTimestamp = stoi(log.substr(pos2 + 1));
			if (currentAction == "start") {
				// start 入栈
				stk.push(make_pair(currentId, currentTimestamp));
			}
			else {
				// end 计算
				int duration = currentTimestamp - stk.top().second + 1;
				result[currentId] += duration;
				stk.pop();
				// 表命此函数是在其他函数内被调用的函数
				if (!stk.empty()) {
					// 让其减去调用函数的持续时间，最终其结果会大于0，
					//  important
					result[stk.top().first] -= duration;
				}
			}
		}
		
		return result;
	}
};
