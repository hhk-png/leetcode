/*
	树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

	给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

	可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

	请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

	树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。

	示例 1：
	输入：n = 4, edges = [[1,0],[1,2],[1,3]]
	输出：[1]
	解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。

	示例 2：
	输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
	输出：[3,4]

	示例 3：
	输入：n = 1, edges = []
	输出：[0]

	示例 4：
	输入：n = 2, edges = [[0,1]]
	输出：[0,1]

*/

class Solution {
public:
	// 算法的总体思想是，一层一层的将度为1的结点删除，最后剩下的所有度为1的结点就是最终结果
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		// 特判
		if (n == 1) return { 0 };
		// 无向图，结点对应的度
		vector<int> degree(n);
		// 邻接表 结点 -> 邻居
		map<int, vector<int>> map;
		// 最终结果
		vector<int> res;
		for (auto edge : edges) {
			// 两个临接结点的度都增加一
			degree[edge[0]]++;
			degree[edge[1]]++;
			// 临接结点互为邻居
			map[edge[0]].push_back(edge[1]);
			map[edge[1]].push_back(edge[0]);
		}

		queue<int> q;
		// 叶子节点入队列
		for (int i = 0; i < n; i++)
			if (degree[i] == 1)
				q.push(i);

		while (!q.empty()) {
			// 清空结果
			res.clear();
			int qSize = q.size(); // 仅用于q的遍历
			for (int i = 0; i < qSize; i++) {
				// 取出队头元素
				int current = q.front(); q.pop();
				// 将其放入最终结果数组
				res.push_back(current);
				// 遍历其邻居，将邻居的度减一，若减一后的度数为0，则入队列
				for (int neighbor : map[current]) {
					degree[neighbor]--;
					if (degree[neighbor] == 1) {
						q.push(neighbor);
					}
				}
			}
		}

		// res中存放的是最后一次遍历的结果，
		return res;
	}
};