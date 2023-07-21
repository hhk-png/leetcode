/*
	给定一个二叉树，判断其是否是一个有效的二叉搜索树。

	假设一个二叉搜索树具有如下特征：

	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。

	示例 1 :
	输入:
	2
	/ \
	1   3
	输出: true


	示例 2 :
	输入 :
	5
	/ \
	1   4
	/ \
	3   6
	输出: false
	解释 : 输入为 : [5, 1, 4, null, null, 3, 6]。
	根节点的值为 5 ，但是其右子节点值为 4 。
*/

// 递归
class Solution {
public:
	bool helper(TreeNode* node, long long lower, long long upper) {
		if (node == nullptr) return true;

		long long val = node->val;
		// 保证 upper(右) > val(中) > lower(左)
		// if(lower!=NULL && val<=lower) return false;
		// if(upper!=NULL && val>=upper) return false;
		if (val <= lower || val >= upper)
			return false;

		// 这样能验证右子树的值大于根节点的值，左子树小于
		return helper(node->right, val, upper) 
			&& helper(node->left, lower, val);
		// if(!helper(node.right, val, upper)) return false;
		// if(!helper(node.left, upper, val)) return false;
		// return true;
	}
	bool isValidBST(TreeNode* root) {
		return helper(root, LLONG_MIN, LLONG_MAX);
	}

};



// 利用中序遍历
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> S;
		long long inorder = LLONG_MIN;
		while (true) {
			while (root) {
				S.push(root);
				root = root->left;
			}

			if (S.empty()) break;

			root = S.top(); S.pop();

			// 更改的地方
			if (inorder >= root->val) return false;
			inorder = root->val;

			root = root->right;
		}
		return true;
	}
};