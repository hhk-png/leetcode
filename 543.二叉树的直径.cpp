/*
	给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 
	示例 :
	给定二叉树
			  1
			 / \
			2   3
		   / \
		  4   5
	返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。


	注意：两结点之间的路径长度是以它们之间边的数目表示。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxMiameter = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		computedMaxDep(root);
		return maxMiameter;
	}
	int computedMaxDep(TreeNode* root) {
		// 节点为空，返回0
		if (root == NULL) {
			return 0;
		}
		// 左子树的最大深度计算
		int left = computedMaxDep(root->left);
		// 右子树的最大深度计算
		int right = computedMaxDep(root->right);

		// 更新当前节点的最大直径
		maxMiameter = max(left + right, maxMiameter);
		// 返回当前节点的深度
		return max(left, right) + 1;
	}
};