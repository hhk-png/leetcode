/*
	给定一个二叉树，找出其最大深度。

	二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

	说明 : 叶子节点是指没有子节点的节点。

		示例：
		给定二叉树[3, 9, 20, null, null, 15, 7]，

		3
		/ \
		9  20
		/ \
		15   7
		返回它的最大深度 3 。
*/

// 递归
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		else {
			int left_height = maxDepth(root->left);
			int right_height = maxDepth(root->right);
			return max(left_height, right_height) + 1;
		}
	}
};

// 迭代
class Solution {
public:
	int maxDepth(TreeNode* root) {
		// 最大深度
		int max_height = 0;
		// 使用队列和pair，保存每个结点和它的深度
		queue<pair<TreeNode*, int>> q;
		// 第一个结点深度为1
		q.push({ root, 1 });

		while (!q.empty()) {
			// 获取当前pair保存的结点和深度
			TreeNode* curr_node = q.front().first;
			int curr_height = q.front().second;
			// 弹出
			q.pop();

			// 如果当前结点不为NULL
			if (curr_node) {
				// update
				max_height = max(max_height, curr_height);
				// 左节点和右节点全插入queue中
				q.push({ curr_node->right, curr_height + 1 });
				q.push({ curr_node->left, curr_height + 1 });
			}
		}
		return max_height;
	}
};