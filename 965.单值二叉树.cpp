/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。


*/

class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (!root) return true;
		int unique = root->val;
		return isSame(root->left, unique)
			&& isSame(root->right, unique);
	}

	bool isSame(TreeNode* root, int unique) {
		if (!root) return true;
		if (root->val != unique) return false;
		return isSame(root->left, unique)
			&& isSame(root->right, unique);
	}
};