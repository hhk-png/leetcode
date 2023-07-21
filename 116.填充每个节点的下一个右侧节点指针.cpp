/*
	给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

	struct Node {
	  int val;
	  Node *left;
	  Node *right;
	  Node *next;
	}
	填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

	初始状态下，所有 next 指针都被设置为 NULL。

 

	进阶：

	你只能使用常量级额外空间。
	使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 

	示例：

	输入：root = [1,2,3,4,5,6,7]
	输出：[1,#,2,3,#,4,5,6,7,#]
	解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
	// Definition for a Node.
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;

		Node() : val(0), left(NULL), right(NULL), next(NULL) {}

		Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {}
	};
*/


class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return root;

		queue<Node*> Q;
		Q.push(root);

		while (!Q.empty()) {
			int len = Q.size();

			for (int i = 0; i < len; i++) {
				Node* node = Q.front();
				Q.pop();

				if (i < len - 1) node->next = Q.front();

				if (node->left != NULL) Q.push(node->left);
				if (node->right != NULL) Q.push(node->right);
			}
		}

		return root;
	}
};


class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return root;

		// 使用leftmost控制二叉树的层次下移
		Node* leftmost = root;

		while (leftmost->left != NULL) {
			// 每一层从leftmost向右操作
			Node* head = leftmost;

			// 本层的每个结点是一个while循环操作
			// 每层的next结点已经在上一层准备完毕，所以可以直接使用
			//	第一层为root，就只有一个结点，所以不使用next就可以完成下一层的next构建操作
			while (head != NULL) {
				// connection1
				head->left->next = head->right;

				// connection2
				if (head->next != NULL) {
					head->right->next = head->next->left;
				}

				// 去同一层的下一个结点
				head = head->next;
			}

			// 本层遍历完毕，去下一层，leftmost -> left
			leftmost = leftmost->left;
		}

		return root;
	}
};