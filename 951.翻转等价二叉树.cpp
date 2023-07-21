class Solution {
public:
	// root1和root2始终处在等价的位置
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		// 两者都为NULL，返回true，
		//  两者不都为NULL，返回false
		// 如果为true，则会将值向上传递，只判断为false的情况就可以
		if (!root1 || !root2) return root1 == root2;

		// 两者不相等，false
		if (root1->val != root2->val) return false;
		return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
			flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
	}
};