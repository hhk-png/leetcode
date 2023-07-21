// ��֤�Ƿ��Ƕ���ƽ����
class Solution {
public:
	int height(TreeNode* root) {
		// ���Ϊ��
		if (!root) return 0;

		// ��㲻Ϊ��
		// �ݹ�������������ĸ߶�
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1) {
			// �״��������ߵ���abs(leftHeight - rightHeight) > 1
			//  һ�����������ߣ��ͱ�־�����������ݹ��еĺ���Ҳ��ͨ��leftHeight��rightHeight return -1
			return -1;
		}
		else {
			// ���ظ߶ȡ�
			return max(leftHeight, rightHeight) + 1;
		}
	}

	bool isBalanced(TreeNode* root) {

		return height(root) >= 0;
	}
};