#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*https://leetcode-cn.com/problems/find-eventual-safe-states/solution/zhao-dao-zui-zhong-de-an-quan-zhuang-tai-by-leetco/*/

/*
在有向图中，从某个节点和每个转向处开始出发，沿着图的有向边走。如果到达的节点是终点（即它没有连出的有向边），则停止。

如果从起始节点出发，最后必然能走到终点，就认为起始节点是 最终安全 的。
	
	更具体地说，对于最终安全的起始节点而言，存在一个自然数 k ，无论选择沿哪条有向边行走 ，走了不到 k 步后必能停止在一个终点上。

返回一个由图中所有最终安全的起始节点组成的数组作为答案。答案数组中的元素应当按 升序 排列。

该有向图有 n 个节点，按 0 到 n - 1 编号，其中 n 是 graph 的节点数。图以下述形式给出：
	graph[i] 是编号 j 节点的一个列表，满足 (i, j) 是图的一条有向边。

 

示例 1：
	输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
	输出：[2,4,5,6]

示例 2：
	输入：graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
	输出：[4]

*/

class Solution {
/*
	当我们第一次访问一个节点时，我们把他从白色变成灰色，并继续搜索与他相连的节点。
	如果在搜索过程中我们遇到了一个灰色的节点，那么说明找到了一个环，此时退出搜索，
		所有的灰色节点标志不变(即从任意一个灰色节点开始，都能走到环中)
	如果我们没有遇到灰色的节点，那么在回溯当前节点时，我们把它从灰色变成黑色，即表示它是一个安全节点
*/
private:
	static constexpr int WHITE = 0;
	static constexpr int GRAY = 1;
	static constexpr int BLACK = 2;
public:
	bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
		// 颜色>0，如果是灰色节点(1)，与2不相等，最终返回的是false
		if (color[node] > 0)
			return color[node] == 2;

		// 变成灰色
		color[node] = 1;
		for (int neibor : graph[node]) {
			// 安全节点
			if (color[neibor] == 2)
				continue;

			// 灰色节点，不安全节点
			if (color[neibor] == 1)
				return false;

			// 只需判断不成功的情况，否则就会破坏原来程序的执行
			if (!dfs(neibor, color, graph))
				return false;
		}

		// 最终没有问题，将node变为黑色节点
		color[node] = 2;
		return true;
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n);
		vector<int> ans;

		for (int i = 0; i < n; i++) {
			if (dfs(i, color, graph))
				ans.push_back(i);
		}

		return ans;
	}
};

class Solution1 {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> outDegree(n, 0); // 维护出度
		vector<vector<int>> rGraph(n, vector<int>{});
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			// 构造每个节点的出度
			outDegree[i] = graph[i].size();
			for (auto& end : graph[i]) {
				// 构建反向graph
				rGraph[end].push_back(i);
			}
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			// 找到出度为0的节点，插入到队列中
			if (outDegree[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int head = q.front(); q.pop();
			ans.push_back(f);
			// 从图中删除f节点，指向f节点的节点出度减一
			for (auto start : rGraph[f]) {
				outDegree[start]--;
				// 如果除去f节点之后出度为0，将其添加到队列中
				if (outDegree[start] == 0)
					q.push(start);
			}
		}

		// 可以使用safe数组代替排序
		sort(ans.begin(), ans.end());
		return ans;
	}
};

