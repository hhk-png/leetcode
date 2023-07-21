/*
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return construct(nums, 0, nums.size());
	}

	TreeNode* construct(vector<int>& nums, int left, int right) {
		// 说明已经到了边界
		if (left == right)
			return NULL;
		// getMaxIndex
		int maxIndex = getMaxIndex(nums, left, right);
		TreeNode* root = new TreeNode(nums[maxIndex]);
		root->left = construct(nums, left, maxIndex);
		root->right = construct(nums, maxIndex + 1, right);

		return root;
	}

	// 最大值索引
	int getMaxIndex(vector<int>& nums, int left, int right) {
		int maxIndex = left;
		for (int i = left; i < right; i++) {
			if (nums[maxIndex] < nums[i])
				maxIndex = i;
		}
		return maxIndex;
	}
};