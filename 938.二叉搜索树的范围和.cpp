/*
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
	int ans;
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		ans = 0;
		dfs(root, low, high);
		return ans;
	}

	int dfs(TreeNode* root, int low, int high) {
		if (root) {
			if (root->val <= high && root->val >= low)
				ans += root->val;
			if (root->val > low)
				dfs(root->left, low, high);
			if (root->val < high) {
				dfs(root->right, low, high);
			}
		}

		return 0;
	}
};