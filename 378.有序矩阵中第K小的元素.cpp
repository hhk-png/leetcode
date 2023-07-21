#include<iostream>
#include<vector>
using namespace std;

/*
	给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
	请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。

	你必须找到一个内存复杂度优于 O(n2) 的解决方案。

 

	示例 1：
		输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
		输出：13
		解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
	
	示例 2：
		输入：matrix = [[-5]], k = 1
		输出：-5

*/


class Solution {
public:
	bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
		int i = n - 1;
		int j = 0;
		int num = 0;
		while (i >= 0 && j < n) {
			// 小于等于mid
			if (matrix[i][j] <= mid) {
				// 向右走，并收集小于 mid 的数个数
				num += i + 1;
				++j;
			} else {
				// 大于mid，向上走
				--i;
			}
		}

		// 返回是否大于k
		return num >= k;
	}

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0];
		int right = matrix[n - 1][n - 1];
		// 使用矩阵的二分查找
		while (left < right) {
			int mid = left + ((right - left) >> 1);
			// 如果矩阵中小于 mid 的数大于等于k，则right应该缩小
			if (check(matrix, mid, k, n)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}

		// left一定在矩阵中，证明略
		return left;
	}
};
