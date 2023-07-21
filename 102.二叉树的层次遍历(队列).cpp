/*
	给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

	例如:
	给定二叉树: [3,9,20,null,null,15,7],

		3
	   / \
	  9  20
		/  \
	   15   7
	返回其层次遍历结果：

	[
	  [3],
	  [9,20],
	  [15,7]
	]
*/



// dfs
class Solution {
public:
	vector<vector<int>> result;
	void dfs(TreeNode* root, int dep) {
		if (!root) return;
		if (dep == result.size()) result.emplace_back();
		result[dep].push_back(root->val);
		dfs(root->left, dep + 1);
		dfs(root->right, dep + 1);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		dfs(root, 0);
		return result;
	}
};

// 迭代
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> output;
		if (!root) return output;
		queue<TreeNode*> que;
		que.push(root);
		int level = 0;

		while (!que.empty()) {
			
			// 添加一个空数组
			output.emplace_back();

			int qLen = que.size();
			for (int i = 0; i < qLen; i++) {
				TreeNode* node = que.front(); que.pop();
				output[level].push_back(node->val);

				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}

			level++;
		}

		return output;
	}
};