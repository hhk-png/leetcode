/*
有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 
	times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， 
	wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？
	如果不能使所有节点收到信号，返回 -1 。

*/

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
		// 从k到对应结点的距离(权重)
		vector<int> distance(n + 1, INT_MAX);
		vector<int> visited(n + 1, 0);
		// 构造有向图，并部分初始化distance
		for (auto& time : times) {
			int from = time[0];
			int to = time[1];
			int weight = time[2];
			graph[from][to] = weight;
			if (from == k)
				distance[to] = weight;
		}
		// 结点0不用
		distance[0] = 0;
		// k为初始结点
		distance[k] = 0;
		// 初始结点已经访问
		visited[k] = 1;
		for (int count = 1; count < n; count++) {
			// 从distance中找到最小的结点，标记为mark
			int weightMin = INT_MAX; // 只是用来判断是否可达
			int mark = 0;
			for (int i = 1; i <= n; i++) {
				if (distance[i] < weightMin && !visited[i]) {
					weightMin = distance[i];
					mark = i;
				}
			}

			// weightMin为INT_MAX说明不可达，直接返回
			if (weightMin == INT_MAX) return -1;
			// 标记mark已访问
			visited[mark] = 1;

			// 以mark为起点进行扩散，更新distance[1~n]的值
			for (int j = 1; j <= n; j++) {
				// mark-j可达，并且经过mark到j的距离要比之前的要短，更新distance[j](k-j)
				if (graph[mark][j] != INT_MAX && distance[j] > distance[mark] + graph[mark][j]) {
					distance[j] = distance[mark] + graph[mark][j];
				}
			}
		}

		// 找最大值
		int res = *max_element(distance.begin(), distance.end());
		return res;
	}
};



class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<int> dis(n + 1, INT_MAX / 2), 
					cnt(n + 1, 0); //cnt表示节点入队次数
		vector<bool> onque(n + 1, false); // 是否再队列中
		unordered_map<int, vector<pair<int, int>>> map; // 图的另一种表示方式
		for (auto& it : times) {
			map[it[0]].push_back(make_pair(it[1], it[2]));
		}
		// k和0设为0
		dis[k] = 0, dis[0] = 0;
		queue<int> que;
		que.push(k); // 初始结点入队列
		onque[k] = true, cnt[k]++; // 
		while (!que.empty()) {
			auto it = que.front(); que.pop();
			onque[it] = false; // 出队列
			for (auto& p : map[it]) {
				int v = p.first, w = p.second;
				/*此时it是u节点,有u->v = w,以u为中心点扩展*/
				if (dis[v] > dis[it] + w) {
					dis[v] = dis[it] + w;
					// 更新之后的v(to)结点重新放入到队列中
					if (!onque[v]) { // 不在队列中
						que.push(v);
						onque[v] = true;
						cnt[v]++; // 入队次数加一
						if (cnt[v] > n)   return -1;//存在负权回路
					}
				}
			}
		}
		int ret = *max_element(dis.begin(), dis.end());
		return ret == INT_MAX / 2 ? -1 : ret;
	}
};

