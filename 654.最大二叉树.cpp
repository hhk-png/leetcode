/*
����һ�������ظ�Ԫ�ص��������� nums ��һ���Դ�����ֱ�ӵݹ鹹���� �������� �������£�

�������ĸ������� nums �е����Ԫ�ء�
��������ͨ�������� ���ֵ��߲��� �ݹ鹹���������������
��������ͨ�������� ���ֵ�ұ߲��� �ݹ鹹���������������
�����и������� nums ������ �������� ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return construct(nums, 0, nums.size());
	}

	TreeNode* construct(vector<int>& nums, int left, int right) {
		// ˵���Ѿ����˱߽�
		if (left == right)
			return NULL;
		// getMaxIndex
		int maxIndex = getMaxIndex(nums, left, right);
		TreeNode* root = new TreeNode(nums[maxIndex]);
		root->left = construct(nums, left, maxIndex);
		root->right = construct(nums, maxIndex + 1, right);

		return root;
	}

	// ���ֵ����
	int getMaxIndex(vector<int>& nums, int left, int right) {
		int maxIndex = left;
		for (int i = left; i < right; i++) {
			if (nums[maxIndex] < nums[i])
				maxIndex = i;
		}
		return maxIndex;
	}
};