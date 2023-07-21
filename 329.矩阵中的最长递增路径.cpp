#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility> // pair
using namespace std;

/*
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

 
*/

class Solution {
public:
	static int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	int longestIncreasingPath(vector<vector<int>> &matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		
		if (rows == 0 || cols == 0) {
			return 0;
		}

		vector<vector<int>> memo(rows, vector<int>(cols));
		int maxn = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				maxn = max(maxn, dfs(matrix, i, j, memo));
			}
		}
		
		return maxn;
	}

	int dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &memo) {
		if (memo[row][col] != 0) {
			return memo[row][col];
		}

		// 此时 memo[row][col] == 0，路线的初始长度是1
		++memo[row][col];

		for (int i = 0; i < 4; ++i) {
			int newRow = row + dirs[i][0];
			int newCol = col + dirs[i][1];
			if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] > matrix[row][col]) {
				// 再次更新 memo[row][col]
				memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);
			}
		}

		return memo[row][col];
	}
};

class Solution {
public:
	static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int rows, cols;

	int longestIncreasingPath(vector<vector<int>> &matrix) {
		rows = matrix.size();
		cols = matrix[0].size();
		if (rows == 0 || cols == 0) {
			return 0;
		}

		vector<vector<int>> outdegrees(rows, vector<int>(cols));

		// 计算出度
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				for (int k = 0; k < 4; ++k) {
					int newRow = i + dirs[k][0];
					int newCol = j + dirs[k][1];
					if (newRow >= 0
						&& newRow < rows
						&& newCol >= 0
						&& newCol < cols
						&& matrix[newRow][newCol] > matrix[i][j]) {

						++outdegrees[i][j];
					}
				}
			}
		}

		// 出度为0的点
		queue<pair<int, int>> que;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (outdegrees[i][j] == 0) {
					que.push({ i, j });
				}
			}
		}

		// 所有出度为0的点同时出发，最终还能向前走的一定是最长的那一条路径
		//	与上一个算法不同，此算法寻找的是最长的递减序列，与递增相同
		int ans = 0;
		while (!que.empty()) {
			++ans;
			int size = que.size();
			for (int i = 0; i < size; ++i) {
				auto cell = que.front(); que.pop();
				int row = cell.first;
				int col = cell.second;
				for (int j = 0; j < 4; ++j) {
					int newRow = row + dirs[j][0];
					int newCol = col + dirs[j][1];
					if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] < matrix[row][col]) {
						--outdegrees[newRow][newCol];
						if (outdegrees[newRow][newCol] == 0) {
							que.push({ newRow, newCol });
						}
					}

				}
			}
		}

		return ans;
	}
};

