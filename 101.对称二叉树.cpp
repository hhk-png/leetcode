/*
	给定一个二叉树，检查它是否是镜像对称的。

	例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

		1
	   / \
	  2   2
	   \   \
	   3    3
*/

// 递归
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return isMirror(root, root);
	}
	bool isMirror(TreeNode* rootLeft, TreeNode* rootRight) {
		// 处理NULL的情况，也是递归的最后情况
		if (rootLeft == NULL && rootRight == NULL) return true;
		if (rootLeft == NULL || rootRight == NULL) return false;

		// 本结点的值是否相同
		// 对称的判断：
		return rootLeft->val == rootRight->val
			&& isMirror(rootLeft->left, rootRight->right)
			&& isMirror(rootLeft->right, rootRight->left);
	}
};

// 使用queue容器
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> p;
		p.push(root->left);
		p.push(root->right);
		while (!p.empty()) {
			TreeNode* p1 = p.front();
			p.pop();
			TreeNode* p2 = p.front();
			p.pop();

			if (p1 == NULL && p2 == NULL) continue;
			if (p1 == NULL || p2 == NULL) return false;

			if (p1->val != p2->val) return false;

			p.push(p1->left);
			p.push(p2->right);
			p.push(p2->left);
			p.push(p1->right);
		}
		return true;
	}
};