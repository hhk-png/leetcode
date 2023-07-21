﻿#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。


示例 1：
	输入：ratings = [1,0,2]
	输出：5
	解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

示例 2：
	输入：ratings = [1,2,2]
	输出：4
	解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
		 第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
*/

class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> left(n);
		for (int i = 0; i < n; ++i) {
			// 相邻的孩子中，评分高的孩子必须获得更多的糖果
			if (i > 0 && ratings[i] > ratings[i - 1]) {
				// 要使评分更高的孩子获得更多的糖果，只需要在评分较低的孩子的基础上加 1 即可
				left[i] = left[i - 1] + 1;
			}
			else {
				// 初始为 1
				left[i] = 1;
			}
		}

		int res = 0, right = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (i < n - 1 && ratings[i] > ratings[i + 1]) {
				++right;
			}
			else {
				right = 1;
			}
			res += max(left[i], right);
		}
		return res;
	}
};