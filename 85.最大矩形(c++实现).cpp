
// 1.
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		int maxArea = 0;
		// 创建一个二维数组，注意
		vector<vector<int> >dp(matrix.size(), vector<int>(matrix[0].size()));

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == '1') {
					// 连续的1的数量，作为矩形的宽度
					dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
					int width = dp[i][j];

					for (int k = i; k >= 0; k--) {
						// 从底往上找矩形的高度，并计算最大面积
						width = min(width, dp[k][j]);
						maxArea = max(maxArea, width * (i - k + 1));
					}

				}
			}
		}

		return maxArea;
	}
};

// 2.