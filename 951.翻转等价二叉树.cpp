class Solution {
public:
	// root1��root2ʼ�մ��ڵȼ۵�λ��
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		// ���߶�ΪNULL������true��
		//  ���߲���ΪNULL������false
		// ���Ϊtrue����Ὣֵ���ϴ��ݣ�ֻ�ж�Ϊfalse������Ϳ���
		if (!root1 || !root2) return root1 == root2;

		// ���߲���ȣ�false
		if (root1->val != root2->val) return false;
		return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
			flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
	}
};