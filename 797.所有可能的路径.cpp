/*
给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点
	（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ）
	空就是没有下一个结点了。


	示例 1：
		输入：graph = [[1,2],[3],[3],[]]
		输出：[[0,1,3],[0,2,3]]
		解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

	示例 2：
		输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
		输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

	示例 3：
		输入：graph = [[1],[]]
		输出：[[0,1]]

	示例 4：
		输入：graph = [[1,2,3],[2],[3],[]]
		输出：[[0,1,2,3],[0,2,3],[0,3]]

	示例 5：
		输入：graph = [[1,3],[2],[3],[]]
		输出：[[0,1,2,3],[0,3]]

*/

class Solution {
private:
	vector<vector<int>> result;
public:
	void dfs(vector<vector<int>>& graph, int curr, vector<int>& ans) {
		if (curr == graph.size() - 1) {
			result.push_back(ans);
			return;
		}
		for (auto neibor : graph[curr]) {
			// 需要回溯，每一个当前节点对应多个邻居，
			//		如果最后不pop_back，就会在原有的完整路径上面继续添加新的完整路径
			ans.push_back(neibor);
			dfs(graph, neibor, ans);
			ans.pop_back();
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> ans{ 0 };
		dfs(graph, 0, ans);

		return result;
	}
};