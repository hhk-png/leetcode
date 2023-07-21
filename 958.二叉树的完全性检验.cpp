
/*给定一个二叉树，确定它是否是一个完全二叉树。*/
/*
	先给每个数组表上号，根节点为i，左右子节点分别为2 * i和2 * i + 1， 根为1
		将已经标上号的结点的index放到数组中，最后比较数组的大小与数组中最大的元素是否相等
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



