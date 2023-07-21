/*
	给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

	百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

	例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]



	示例 1:

	输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
	输出: 6
	解释: 节点 2 和节点 8 的最近公共祖先是 6。

	示例 2:
	输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
	输出: 2
	解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
	两种解决方案的相同点都是从根节点向下找，
	本质是相同的
*/

// 先分别获取root结点到p和q所经过的结点，然后对比这两组结点，找到第一个不相等的结点
//		就是ancestor结点，找不到就是null
class Solution {
public:
	vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
		vector<TreeNode*> path;
		TreeNode* node = root;

		while (node != target) {
			path.push_back(node);
			if (node->val < target->val) {
				node = node->right;
			}
			else if (node->val > target->val) {
				node = node->left;
			}
		}

		path.push_back(node);

		return path;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path_p = getPath(root, p);
		vector<TreeNode*> path_q = getPath(root, q);

		TreeNode* ancestor;
		int len = min(path_p.size(), path_q.size());
		for (int i = 0; i < len; i++) {
			if (path_p[i] == path_q[i]) {
				ancestor = path_q[i];
			}
			else {
				break;
			}
		}

		return ancestor;
	}
};

// 直接使用root结点向下寻找，如果root不是p和q共同的祖先，那么要么比p和q都小，要么比p和q都大
//		找到一个值在p和q中间的结点，这个结点就是ancestor结点
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* ancestor = root;
		while (true) {
			if (ancestor->val < p->val && ancestor->val < q->val) {
				ancestor = ancestor->right;
			}
			else if (ancestor->val > p->val && ancestor->val > q->val) {
				ancestor = ancestor->left;
			}
			else {
				break;
			}
		}

		return ancestor;
	}
};

