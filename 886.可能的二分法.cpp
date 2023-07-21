/*
	给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组。

	每个人都可能不喜欢其他人，那么他们不应该属于同一组。

	形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组。

	当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。

 

	示例 1：
		输入：N = 4, dislikes = [[1,2],[1,3],[2,4]]
		输出：true
		解释：group1 [1,4], group2 [2,3]

	示例 2：
		输入：N = 3, dislikes = [[1,2],[1,3],[2,3]]
		输出：false

	示例 3：
		输入：N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
		输出：false
*/

class Solution {
private:
	unordered_map<int, vector<int>> graph;
	unordered_map<int, int> group;
public:
	// 将node分配到id组
	bool dfs(int node, int id) {
		// node已经分配相应的分组，看是否与现在要分配的分组相同
		if (group.find(node) != group.end())
			return group[node] == id;
		group[node] = id;
		for (auto dislike : graph[node]) {
			// 将邻居分配到(!id)组，若分配失败，返回false
			if (!dfs(dislike, id ^ 1))
				return false;
		}

		// 分配成功
		return true;
	}

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		for (auto it : dislikes) {
			graph[it[0]].push_back(it[1]);
			graph[it[1]].push_back(it[0]);
		}
		for (int i = 1; i <= N; i++) {
			// 初始时i节点不在group中，尝试为其分配0号分组
			if (group.find(i) == group.end() && !dfs(i, 0))
				return false;
		}
		return true;
	}
};