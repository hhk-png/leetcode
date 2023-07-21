
/*����һ����������ȷ�����Ƿ���һ����ȫ��������*/
/*
	�ȸ�ÿ��������Ϻţ����ڵ�Ϊi�������ӽڵ�ֱ�Ϊ2 * i��2 * i + 1�� ��Ϊ1
		���Ѿ����ϺŵĽ���index�ŵ������У����Ƚ�����Ĵ�С������������Ԫ���Ƿ����
*/

class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		if (!root) return false;
		vector<unsigned int> vec = { 1 };
		helper(root, 1, vec);
		return vec.size() == *(max_element(vec.begin(), vec.end()));
	}

	void helper(TreeNode* root, unsigned int index, vector<unsigned int>& vec) {
		if (root->left) {
			vec.push_back(2 * index);
			helper(root->left, 2 * index, vec);
		}
		if (root->right) {
			vec.push_back(2 * index + 1);
			helper(root->right, 2 * index + 1, vec);
		}
	}
};



