class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> S;
		while (true) {
			// 将左节点 从上到下 压入栈中
			while (root) {
				S.push(root);
				root = root->left;
			}

			// 右节点，或根节点没有左节点时，退出
			if (S.empty()) break;

			// 左节点依此出栈
			root = S.top(); S.pop();

			v.push_back(root->val);

			// 转向右侧，继续遍历
			root = root->right;
		}
		return v;
	}
};