class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> S;
		while (true) {
			// ����ڵ� ���ϵ��� ѹ��ջ��
			while (root) {
				S.push(root);
				root = root->left;
			}

			// �ҽڵ㣬����ڵ�û����ڵ�ʱ���˳�
			if (S.empty()) break;

			// ��ڵ����˳�ջ
			root = S.top(); S.pop();

			v.push_back(root->val);

			// ת���Ҳ࣬��������
			root = root->right;
		}
		return v;
	}
};