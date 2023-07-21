#include<iostream>
#include<vector>
using namespace std;

int Prim(vector<vector<int>> map, int n) {
	vector<int> visited(n);
	vector<int> low(n, INT_MAX);
	int result = 0;
	// 选中初始结点为0，然后更新low数组
	int pos = 0;
	for (int i = 1; i < n; i++) {
		low[i] = map[pos][i];
	}

	for (int i = 1; i < n; i++) {
		// 从low数组中找出最小值，并记录最小值所在的点
		int minV = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && minV > low[i]) {
				minV = low[i];
				pos = i;
			}
		}

		// 增加权重
		result += minV;
		// 结点已经访问过
		visited[pos] = 1;

		// 以新的pos为起点更新low数组的值
		for (int i = 0; i < n; i++) {
			if (!visited[i] && low[i] > map[pos][i])
				low[i] = map[pos][i];
		}

		return result;
	}
}

