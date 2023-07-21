class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> reuslt;
		if (!root) return reuslt;

		stack<TreeNode*> stk;
		while (!stk.empty() || root) {
			// ×ó
			while (root) {
				// ÖÐ
				reuslt.push_back(root->val);
				stk.push(root);
				root = root->left;
			}
			root = stk.top(); stk.pop();
			// ÓÒ
			root = root->right;
		}

		return reuslt;
	}
};