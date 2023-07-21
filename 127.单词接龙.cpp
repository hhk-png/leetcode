#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

/*
	字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列
	 	 beginWord -> s1 -> s2 -> ... -> sk：

	每一对相邻的单词只差一个字母。
	对于 1 <= i <= k 时，每个 si 都在 wordList 中。
		注意， beginWord 不需要在 wordList 中。sk == endWord

	给你两个单词 beginWord 和 endWord 和一个字典 wordList ，
	返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。
	如果不存在这样的转换序列，返回 0 。

 
示例 1：
	输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
	输出：5
	解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。

示例 2：
	输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
	输出：0
	解释：endWord "cog" 不在字典中，所以无法进行转换。
 

提示：
	1 <= beginWord.length <= 10
	endWord.length == beginWord.length
	1 <= wordList.length <= 5000
	wordList[i].length == beginWord.length
	beginWord、endWord 和 wordList[i] 由小写英文字母组成
	beginWord != endWord
	wordList 中的所有字符串 互不相同

*/

class Solution {
public:
	// 将所有的单词用id表示
	unordered_map<string, int> wordId;
	// 存储一个图
	// 此图中，节点与节点之间的代价均为 1
	vector<vector<int>> edge;
	// ID编号
	int nodeNum = 0;

	void addWord(string& word) {
		// 如果之前没有存储过此word
		if (!wordId.count(word)) {
			// 为其编号
			wordId[word] = nodeNum++;
			// 并在图中为其开辟出一个位置
			edge.emplace_back();
		}
	}

	void addEdge(string& word) {
		// 先将原来的单词放入wordId中
		addWord(word);
		// 并获取它的ID号
		int id1 = wordId[word];
		// 分别将每个字母换成 '*'，再组成一个无向图
		for (char& it : word) {
			// 此次遍历被换掉的字母
			char tmp = it;
			it = '*';
			// 添加到WordId
			addWord(word);
			// 获取其ID号
			int id2 = wordId[word];
			// 两个节点连接
			edge[id1].push_back(id2);
			edge[id2].push_back(id1);
			// 替换成原单词
			it = tmp;
		}
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// wordList里面的单词，放入wordId，并创建图
		for (string& word : wordList) {
			addEdge(word);
		}
		// beginWord 或许不包括在 wordList 中
		addEdge(beginWord);
		// 如果 wordList 中没有 endWord，返回0
		if (!wordId.count(endWord)) {
			return 0;
		}

		// 起始单词的 ID
		int beginId = wordId[beginWord];
		// 结束单词的 ID
		int endId = wordId[endWord];
		// 从开始单词到所有节点的距离
		vector<int> dis(nodeNum, INT_MAX);
		dis[beginId] = 0;
		// BFS
		queue<int> que;
		que.push(beginId);
		while (!que.empty()) {
			int x = que.front(); que.pop();
			// 到达了最后的单词
			if (x == endId) {
				// 因为添加了虚拟节点，所以我们得到的距离为实际最短路径长度的两倍。
				//		同时我们并未计算起点对答案的贡献，所以我们应当返回距离的一半再加一的结果。
				return dis[endId] / 2 + 1;
			}

			// 向外扩散
			for (int& it : edge[x]) {
				// 节点还没有更新过
				if (dis[it] == INT_MAX) {
					dis[it] = dis[x] + 1;
					que.push(it);
				}
			}
		}
		
		return 0;
	}
};

class Solution {
public:
	unordered_map<string, int> wordId;
	vector<vector<int>> edge;
	int nodeNum = 0;

	void addWord(string& word) {
		if (!wordId.count(word)) {
			wordId[word] = nodeNum++;
			edge.emplace_back();
		}
	}

	void addEdge(string& word) {
		addWord(word);
		int id1 = wordId[word];
		for (char& it : word) {
			char tmp = it;
			it = '*';
			addWord(word);
			int id2 = wordId[word];
			edge[id1].push_back(id2);
			edge[id2].push_back(id1);
			it = tmp;
		}
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		for (string& word : wordList) {
			addEdge(word);
		}
		addEdge(beginWord);
		if (!wordId.count(endWord)) {
			return 0;
		}

		// 如果使用两个同时进行的广搜可以有效地减少搜索空间。
		// 一边从 beginWord 开始，另一边从 endWord 开始。
		// 我们每次从两边各扩展一层节点，
		// 当发现某一时刻两边都访问过同一顶点时就停止搜索。
		// 这就是双向广度优先搜索，它可以可观地减少搜索空间大小，从而提高代码运行效率。

		int idBegin = wordId[beginWord];
		vector<int> disBegin(nodeNum, INT_MAX);
		disBegin[idBegin] = 0;
		queue<int> queBegin;
		queBegin.push(idBegin);

		int idEnd = wordId[endWord];
		vector<int> disEnd(nodeNum, INT_MAX);
		disEnd[idEnd] = 0;
		queue<int> queEnd;
		queEnd.push(idEnd);

		while (!queBegin.empty() && !queEnd.empty()) {
			int lenQueBegin = queBegin.size();
			for (int i = 0; i < lenQueBegin; i++) {
				int nodeBegin = queBegin.front();
				queBegin.pop();
				// 如果从 endWord 出发的路线已经经过此节点，就表明遇到了两边都访问过的节点，停止搜索。返回最终结果
				if (disEnd[nodeBegin] != INT_MAX) {
					return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
				}
				for (int& it : edge[nodeBegin]) {
					if (disBegin[it] == INT_MAX) {
						disBegin[it] = disBegin[nodeBegin] + 1;
						queBegin.push(it);
					}
				}
			}

			int lenQueEnd = queEnd.size();
			for (int i = 0; i < lenQueEnd; i++) {
				int nodeEnd = queEnd.front(); queEnd.pop();
				if (disBegin[nodeEnd] != INT_MAX) {
					return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
				}
				for (int& it : edge[nodeEnd]) {
					if (disEnd[it] == INT_MAX) {
						disEnd[it] = disEnd[nodeEnd] + 1;
						queEnd.push(it);
					}
				}
			}
		}


		return 0;
	}
};




