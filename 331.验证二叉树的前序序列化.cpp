/*
序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

	 _9_
	/   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

示例 1:

输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
示例 2:

输入: "1,#"
输出: false
示例 3:

输入: "9,#,#,1"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	bool isValidSerialization(string preorder) {
		int n = preorder.length();
		int i = 0;
		stack<int> stk;
		// 根节点占用的槽位
		stk.push(1);
		while (i < n) {
			// 栈空，flase
			if (stk.empty()) return false;
			if (preorder[i] == ',') {
				// 遇到逗号，无意义，前进一位
				i++;
			}
			else if (preorder[i] == '#') {
				// 遇到空位，去掉当前的一个槽位
				stk.top() -= 1;
				// 当前槽位为0，弹出栈顶元素
				if (stk.top() == 0) {
					stk.pop();
				}
				i++;
			}
			else {
				// 读取一个数字
				while (i < n && preorder[i] != ',') {
					i++;
				}

				stk.top() -= 1;
				if (stk.top() == 0) {
					stk.pop();
				}
				// 又能新开一层，2个槽位，
				//  只有在这个地方才能新开槽位
				stk.push(2);
				// 此处遇到错误，因为上面的while循环中已经进行完指针的移动，所以此处不再需要前进一个位置
				// i++;
			}
		}
		// 如果栈已空，说明满足条件
		return stk.empty();
	}
};