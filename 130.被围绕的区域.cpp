/*
	给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

	找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

	示例:
	X X X X
	X O O X
	X X O X
	X O X X

	运行你的函数后，矩阵变为：
	X X X X
	X X X X
	X X X X
	X O X X

	解释:
	被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/surrounded-regions
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
	本题要求将所有被字母 X 包围的字母 O都变为字母 X ，但很难判断哪些 O 是被包围的，哪些 O 不是被包围的。

	注意到题目解释中提到：任何边界上的 O 都不会被填充为 X。 我们可以想到，所有的不被包围的 O 都直接或间接与边界上的 O 相连。我们可以利用这个性质判断 O 是否在边界上，具体地说：

	对于每一个边界上的 O，我们以它为起点，标记所有与它直接或间接相连的字母 O；
	最后我们遍历这个矩阵，对于每一个字母：
	如果该字母被标记过，则该字母为没有被字母 X 包围的字母 O，我们将其还原为字母 O；
	如果该字母没有被标记过，则该字母为被字母 X 包围的字母 O，我们将其修改为字母 X。

	作者：LeetCode-Solution
	链接：https://leetcode-cn.com/problems/surrounded-regions/solution/bei-wei-rao-de-qu-yu-by-leetcode-solution/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
	将与边界上的O及相连的O找出来，剩下的0就是被包裹的
*/

// BFS
class Solution {
public:
	int n, m;

	// 标注边界上为0的地方
	void dfs(vector<vector<char>>& board, int x, int y) {
		// 超出边界，或者不为0，return
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
			return;
		}
		board[x][y] = 'A';
		dfs(board, x + 1, y);
		dfs(board, x - 1, y);
		dfs(board, x, y + 1);
		dfs(board, x, y - 1);
	}

	void solve(vector<vector<char>>& board) {
		n = board.size();
		if (n == 0) {
			return;
		}
		m = board[0].size();
		for (int i = 0; i < n; i++) {
			dfs(board, i, 0);
			dfs(board, i, m - 1);
		}
		for (int i = 1; i < m - 1; i++) {
			dfs(board, 0, i);
			dfs(board, n - 1, i);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'A') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};


// DFS
class Solution {
public:
	// 用于queue中的pair向上下左右移动
	const int dx[4] = { 1, -1, 0, 0 };
	const int dy[4] = { 0, 0, 1, -1 };

	void solve(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0) {
			return;
		}
		int m = board[0].size();
		queue<pair<int, int>> que;
		// 向queue中添加board中为0的元素的位置
		// 矩阵的最左边一列和最右边一列
		for (int i = 0; i < n; i++) {
			if (board[i][0] == 'O') {
				que.emplace(i, 0);
			}
			if (board[i][m - 1] == 'O') {
				que.emplace(i, m - 1);
			}
		}
		// 最上边一行和最下边一行，
		//	只扫描中间的元素，除去两边的元素，也就是放弃四个边角的扫描，
		//	因为上面已经扫描过了，再次扫描反而会造成最终的结果出错
		for (int i = 1; i < m - 1; i++) {
			if (board[0][i] == 'O') {
				que.emplace(0, i);
			}
			if (board[n - 1][i] == 'O') {
				que.emplace(n - 1, i);
			}
		}
		// 开始向四周扫描
		while (!que.empty()) {
			int x = que.front().first, y = que.front().second;
			que.pop();
			board[x][y] = 'A';
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i], my = y + dy[i];
				if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
					continue;
				}
				que.emplace(mx, my);
			}
		}

		// last
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'A') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};
