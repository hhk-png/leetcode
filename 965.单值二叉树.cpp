/*
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������

ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��


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