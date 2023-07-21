/*
	给定一个二叉树，原地将它展开为链表。

	例如，给定二叉树

		1
	   / \
	  2   5
	 / \   \
	3   4   6
	将其展开为：

	1
	 \
	  2
	   \
		3
		 \
		  4
		   \
			5
			 \
			  6
*/

class Solution {
public:
	void flatten(TreeNode* root) {
		while (root) { 
			if (root->left == NULL) {
				root = root->right;
			} else {
				// 找到root左子树的最右边的结点
				TreeNode* pre = root->left;
				while (pre->right) {
					pre = pre->right;
				}

				// 拼接：把root->left到root*->right这一条直线上的结点，插入到root->right到root->right->right之间
				pre->right = root->right;
				root->right = root->left;
				
				// 将左节点置为空
				root->left = NULL;

				// 从root向右处理
				root = root->right;
			}
		}
	}
};