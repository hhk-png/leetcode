﻿/*
给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)

示例1:
输入: [1,null,0,0,1]
输出: [1,null,0,null,1]

解释:
只有红色节点满足条件“所有不包含 1 的子树”。
右图为返回的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-pruning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (!root) return NULL;

		// 左右子树
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);

		// root值为0，左右子树都为NULL，可以剪枝
		if (!root->left && !root->right && root->val == 0) return NULL;

		// 返回结果
		return root;
	}
};