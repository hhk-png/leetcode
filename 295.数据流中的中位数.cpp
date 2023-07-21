#include<iostream>
#include<queue> // priority_queue
#include<functional> // less greater
#include<vector>
#include<set> // multiset
#include<cstddef> // size_t
using namespace std;

/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，
	[2,3,4] 的中位数是 3

	[2,3] 的中位数是 (2 + 3) / 2 = 2.5


设计一个支持以下两种操作的数据结构：
	void addNum(int num) - 从数据流中添加一个整数到数据结构中。
	double findMedian() - 返回目前所有元素的中位数。

示例：
	addNum(1)
	addNum(2)
	findMedian() -> 1.5
	addNum(3)
	findMedian() -> 2

进阶:
	如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
	如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

*/

class MedianFinder {
public:
	// 低索引部分，大根堆
	priority_queue<int, vector<int>, less<int>> queMin;
	// 高索引部分，小根堆
	priority_queue<int, vector<int>, greater<int>> queMax;

	// 优先级队列最终的状态只有 
	//		1. queMin.size() == queMax.size()
	//		2. queMin.size() == queMax.size() + 1
	// 这两种情况
	// 
		

	MedianFinder() {}

	void addNum(int num) {
		// 当queMin的大小为0(初始)时，或者num小于queMin的最大值
		if (queMin.empty() || num <= queMin.top()) {
			queMin.push(num);
			// 只有处于第二种情况，且向queMin中再插入一个元素时才需要调整
			//		此时 size(queMin) - 2 等于 size(queMax)
			if (queMax.size() + 1 < queMin.size()) {
				// 将queMin顶部的一个元素拿出来放入queMax即可
				queMax.push(queMin.top());
				queMin.pop();
			}
		}
		else {
			// 向queMax插入元素
			queMax.push(num);
			// 当插入元素前，queMax的长度等于queMin，此时又向queMax中插入元素时，需要调整
			if (queMax.size() > queMin.size()) {
				// 保持第二种情况
				queMin.push(queMax.top());
				queMax.pop();
			}
		}
	}

	double findMedian() {
		// 第二种情况，总数为奇数，返回queMin的最大值
		if (queMin.size() > queMax.size()) {
			return queMin.top();
		}
		// 第二种情况
		return (queMin.top() + queMax.top()) / 2.0; // /2.0
	}
};


class MedianFinder {
	// 底层是红黑树
	// 相当于一个自动排序的序列
	multiset<int> nums;
	multiset<int>::iterator left, right;

public:
	MedianFinder() :left(nums.end()), right(nums.end()) {}

	void addNum(int num) {
		const size_t n = nums.size();
		
		// 先向 nums 中插入元素
		nums.insert(num);
		if (!n) {
			left = right = nums.begin();
		} else if (n & 1) { // n 为奇数
			if (num < *left) {
				left--;
			} else {
				right++;
			}
		} else { // 插入 num 后，n 为偶数
			if (num > *left && num < *right) { // left < num < right
				left++;
				right--;
			} else if (num >= *right) { // right <= num
				left++;
			} else { // num <= left
				// 此时num可能插入到 left 和 right 中间，
				right--;
				left = right;
			}

		}
	}

	double findMedian() {
		return (*left + *right) / 2.0;
	}
};


