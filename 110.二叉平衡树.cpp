// 验证是否是二叉平衡树
class Solution {
public:
	int height(TreeNode* root) {
		// 结点为空
		if (!root) return 0;

		// 结点不为空
		// 递归计算左右字数的高度
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1) {
			// 首次走这条线的是abs(leftHeight - rightHeight) > 1
			//  一旦走了这条线，就标志结束，其他递归中的函数也会通过leftHeight和rightHeight return -1
			return -1;
		}
		else {
			// 返回高度。
			return max(leftHeight, rightHeight) + 1;
		}
	}

	bool isBalanced(TreeNode* root) {

		return height(root) >= 0;
	}
};