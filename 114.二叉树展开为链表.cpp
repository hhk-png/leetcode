/*
	����һ����������ԭ�ؽ���չ��Ϊ����

	���磬����������

		1
	   / \
	  2   5
	 / \   \
	3   4   6
	����չ��Ϊ��

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
				// �ҵ�root�����������ұߵĽ��
				TreeNode* pre = root->left;
				while (pre->right) {
					pre = pre->right;
				}

				// ƴ�ӣ���root->left��root*->right��һ��ֱ���ϵĽ�㣬���뵽root->right��root->right->right֮��
				pre->right = root->right;
				root->right = root->left;
				
				// ����ڵ���Ϊ��
				root->left = NULL;

				// ��root���Ҵ���
				root = root->right;
			}
		}
	}
};