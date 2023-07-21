/*
	有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi 的双向路径。在每个花园中，你打算种下四种花之一。

	另外，所有花园 最多 有 3 条路径可以进入或离开.

	你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

	以数组形式返回 任一 可行的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1、2、3、4 表示。保证存在答案。

 

	示例 1：

	输入：n = 3, paths = [[1,2],[2,3],[3,1]]
	输出：[1,2,3]
	解释：
	花园 1 和 2 花的种类不同。
	花园 2 和 3 花的种类不同。
	花园 3 和 1 花的种类不同。
	因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
	示例 2：

	输入：n = 4, paths = [[1,2],[3,4]]
	输出：[1,2,1,2]
	示例 3：

	输入：n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
	输出：[1,2,3,4]
*/

class Solution {
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<vector<int>> G(n);
		// 建立邻接表，无向图
		for (int i = 0; i < paths.size(); i++) {
			G[paths[i][0] - 1].push_back(paths[i][1] - 1);
			G[paths[i][1] - 1].push_back(paths[i][0] - 1);
		}

		vector<int> answer(n, 0);
		for (int i = 0; i < n; i++) {
			// 染色集
			set<int> col_set{ 1, 2, 3, 4 };
			// 去除已经染掉的颜色，与i相邻的结点的颜色
			for (int j = 0; j < G[i].size(); j++) {
				col_set.erase(answer[G[i][j]]);
			}
			// 染上第一个未染上的颜色
			answer[i] = *(col_set.begin());
		}

		return answer;
	}
};