#include<iostream> 
#include<deque>
#include<vector>
using namespace std;
/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。
*/


class MonotonicQueue {
private:
	deque<int> data;
public:
	void push(int n) {
		while (!data.empty() && data.back() < n)
			data.pop_back();
		data.push_back(n);
	}

	int max() { return data.front(); }

	void pop(int n) {
		if (!data.empty() && data.front() == n)
			data.pop_front();
	}
};
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		
		if (nums.size()*k == 0) return new int[0];
		if (k == 1) return nums;

		
		MonotonicQueue window;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			if (i < k - 1) { //先填满窗口的前 k - 1
				window.push(nums[i]);
			}
			else { // 窗口向前滑动
				window.push(nums[i]);
				res.push_back(window.max());
				window.pop(nums[i - k + 1]);
			}
		}
		return res;
	}
};