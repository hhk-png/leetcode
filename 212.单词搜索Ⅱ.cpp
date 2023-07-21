#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;
/*
	给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。

	单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。



	示例 1：
		输入：board = [["o", "a", "a", "n"], ["e", "t", "a", "e"], ["i", "h", "k", "r"], ["i", "f", "l", "v"]], words = ["oath", "pea", "eat", "rain"]
		输出：["eat", "oath"]

	示例 2：
		输入：board = [["a", "b"], ["c", "d"]], words = ["abcb"]
		输出：[]


		m == board.length
		n == board[i].length
		1 <= m, n <= 12
		board[i][j] 是一个小写英文字母
		1 <= words.length <= 3 * 104
		1 <= words[i].length <= 10
		words[i] 由小写英文字母组成
		words 中的所有字符串互不相同

*/

//struct TrieNode {
//	string word;
//	unordered_map<char, TrieNode *> children;
//	TrieNode() {
//		this->word = "";
//	}
//};
//
//void insertTrie(TrieNode * root, const string & word) {
//	TrieNode * node = root;
//	for (auto c : word) {
//		if (!node->children.count(c)) {
//			node->children[c] = new TrieNode();
//		}
//		node = node->children[c];
//	}
//	node->word = word;
//}
//
//class Solution {
//public:
//	int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//	bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
//		char ch = board[x][y];
//		if (!root->children.count(ch)) {
//			return false;
//		}
//		root = root->children[ch];
//		if (root->word.size() > 0) {
//			res.insert(root->word);
//		}
//
//		board[x][y] = '#';
//		for (int i = 0; i < 4; ++i) {
//			int nx = x + dirs[i][0];
//			int ny = y + dirs[i][1];
//			if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
//				if (board[nx][ny] != '#') {
//					dfs(board, nx, ny, root, res);
//				}
//			}
//		}
//		board[x][y] = ch;
//
//		return true;
//	}
//
//	vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
//		TrieNode * root = new TrieNode();
//		set<string> res;
//		vector<string> ans;
//
//		for (auto & word : words) {
//			insertTrie(root, word);
//		}
//		for (int i = 0; i < board.size(); ++i) {
//			for (int j = 0; j < board[0].size(); ++j) {
//				dfs(board, i, j, root, res);
//			}
//		}
//		for (auto & word : res) {
//			ans.emplace_back(word);
//		}
//		return ans;
//	}
//};


// 前缀树节点
struct TrieNode {
	// 存储的单词，除单词所能达到的最后一个节点以外，其他的中间节点的 word 都为空
	string word;
	// 指向子节点的指针
	unordered_map<char, TrieNode*> children;
	TrieNode() {
		this->word = "";
	}
};

// 向 root 中插入 words
void insertTrie(TrieNode* root, string& word) {
	TrieNode* node = root;
	// 遍历words，c为单个字母
	for (auto& c : word) {
		// words中所有的字符串互不相同，
		//	如果node的子节点中 c 的个数为空
		if (!node->children.count(c)) {
			// 就向下拓展子节点
			node->children[c] = new TrieNode();
		}
		// 进入子节点，向下迭代
		node = node->children[c];
	}
	// 最后一个节点的 word
	node->word = word;
}


class Solution {
public:
	// 分别向四个方向进行 dfs
	int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
		// 先保存 board 当前位置的字符
		char ch = board[x][y];
		// 如果此节点为空，或者已经没有了向下走的路，则返回
		if (root == nullptr || !root->children.count(ch)) {
			return false;
		}

		// 下一个 TrieNode 节点
		TrieNode* nxt = root->children[ch];
		// 到达了末尾的节点
		if (nxt->word.size() > 0) {
			// 保存结果
			res.insert(nxt->word);
			// 将匹配到的单词从前缀树中移除，来避免寻找相同的单词，
			//		因为这种方法可以保证每个单词只能被匹配一次，所以我们也不需要再对结果去重了
			nxt->word = "";
		}

		// 下一个节点的 children 不为空
		if (!nxt->children.empty()) {
			// 进行回溯
			board[x][y] = '#';
			// 四个方向
			for (int i = 0; i < 4; i++) {
				int nx = x + dirs[i][0];
				int ny = y + dirs[i][1];
				if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
					// 已经被访问过的节点不在进行访问
					if (board[nx][ny] != '#') {
						dfs(board, nx, ny, nxt, res);
					}
				}
			}
			board[x][y] = ch;
		}
		// 下一个节点为最后一个节点，
		if (nxt->children.empty()) {
			// 就将下一个节点删除
			root->children.erase(ch);
		}

		return true;
	}

	vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
		// 根节点
		TrieNode* root = new TrieNode();
		// set 自带去重功能，先用 set 存放结果，
		set<string> res;
		// 最后转移到 vector 中去
		vector<string> ans;
		
		// 构造前缀树
		for (auto& word : words) {
			insertTrie(root, word);
		}

		// 遍历 board 的所有节点
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				dfs(board, i, j, root, res);
			}
		}

		// 可以不用set去重了，也不需要这一步了
		for (auto& c : res) {
			ans.emplace_back(c);
		}

		return ans;
	}
};




