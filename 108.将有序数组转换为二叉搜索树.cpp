/*
	将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

	本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

	示例:

	给定有序数组: [-10,-3,0,5,9],

	一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

		  0
		 / \
	   -3   9
	   /   /
	 -10  5

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		// 抽取规定范围内中间值作为根节点，然后不断递归下去
		return helper(nums, 0, nums.size() - 1);
	}

	TreeNode* helper(vector<int>& nums, int left, int right) {
		if (left > right) return nullptr;

		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(nums, left, mid - 1);
		root->right = helper(nums, mid + 1, right);
		return root;
	}
};