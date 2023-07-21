/*
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
	给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。
	形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。
	该无向图同时具有以下属性：
		不存在自环（graph[u] 不包含 u）。
		不存在平行边（graph[u] 不包含重复值）。
		如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
		这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，
		并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 。
*/

class Solution {
private:
	// 标记节点未被访问过
	static constexpr int UNCLOSED = 1;
	static constexpr int RED = 2;
	static constexpr int GREEN = 3;
	bool valid;
	vector<int> color;

public:
	void dfs(vector<vector<int>>& graph, int c, int curr) {
		color[curr] = c;
		int cNei = (c == RED) ? GREEN : RED;
		for (auto neibor : graph[curr]) {
			if (color[neibor] == UNCLOSED) {
				dfs(graph, cNei, neibor);
				if (!valid) {
					return;
				}
			}
			else if (color[neibor] != cNei) {
				valid = false;
				return;
			}
		}
	}
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		valid = true;
		color.assign(n, UNCLOSED);
		for (int i = 0; i < n && valid; i++) {
			if (color[i] == UNCLOSED)
				dfs(graph, RED, i);
		}

		return valid;
	}
};