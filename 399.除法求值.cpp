#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

/*
	给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
		其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。
		每个 Ai 或 Bi 是一个表示单个变量的字符串。

	另有一些以数组 queries 表示的问题，
		其中 queries[j] = [Cj, Dj] 表示第 j 个问题，
		请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

	返回 所有问题的答案 。
		如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
		如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

	注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，
			且不存在任何矛盾的结果。

 

	示例 1：
		输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
		输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
		解释：
		条件：a / b = 2.0, b / c = 3.0
		问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
		结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
	示例 2：
		输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
		输出：[3.75000,0.40000,5.00000,0.20000]
	示例 3：
		输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
		输出：[0.50000,2.00000,-1.00000,-1.00000]
 

	提示：
		1 <= equations.length <= 20
		equations[i].length == 2
		1 <= Ai.length, Bi.length <= 5
		values.length == equations.length
		0.0 < values[i] <= 20.0
		1 <= queries.length <= 20
		queries[i].length == 2
		1 <= Cj.length, Dj.length <= 5
		Ai, Bi, Cj, Dj 由小写英文字母与数字组成
*/

class Solution {
public:
	vector<double> res;
	bool notFound;
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		// 有向无环图，double为权重
		unordered_map<string, vector<pair<string, double>>> graph;
		// 以访问结点，字符
		unordered_map<string, int> visit;

		// 创建有向无环图
		for (int i = 0; i < equations.size(); i++) {
			string from = equations[i][0];
			string to = equations[i][1];
			graph[from].push_back(make_pair(to, values[i]));
			graph[to].push_back(make_pair(from, 1.0 / values[i]));
		}

		for (int i = 0; i < queries.size(); i++) {
			string qFrom = queries[i][0];
			string qTo = queries[i][1];
			// 图中没有对应起始结点，graph指向graph.end()
			if (graph.find(qFrom) == graph.end()) {
				// 插入-1.0
				res.push_back(-1.0);
				continue;
			}

			// 初始为true
			notFound = true;
			visit[qFrom] = 1;
			dfs(graph, visit, qFrom, qTo, 1);
			visit[qFrom] = 0;

			// 存在某个无法确定的答案
			if (notFound) {
				res.push_back(-1.0);
			}
		}

		return res;
	}

	// graph：用map构建的有向无环图
	// visit：访问数组
	// currentFrom：当前起始的结点
	// target：目标节点
	// path：从最初的from到currentFrom积累的权重
	void dfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_map<string, int>& visit, string currentFrom, const string& target, const double& path) {
		// 已经找到，返回
		if (notFound == false) {
			return;
		}

		// 找到target，push相应的path
		if (currentFrom == target) {
			notFound = false;
			res.push_back(path);
			return;
		}

		for (int i = 0; i < graph[currentFrom].size(); i++) {
			// 更换起始结点
			string from = graph[currentFrom][i].first;
			// 权重
			double weight = graph[currentFrom][i].second;
			if (visit[from] == 0) {
				// 进行最高层dfs的时候，相应的visit是默认值
				visit[from] = 1;
				dfs(graph, visit, from, target, path * weight);
				visit[from] = 0;
			}
		}
	}
};





