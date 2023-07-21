/*
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。
 

示例 1：

输入： "()"
输出： 1
示例 2：

输入： "(())"
输出： 2
示例 3：

输入： "()()"
输出： 2
示例 4：

输入： "(()(()))"
输出： 6
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	int scoreOfParentheses(string S) {
		stack<int> stk;
		stk.push(0);
		// 我们用一个栈来维护当前所在的深度，以及每一层深度的得分。
		// 当我们遇到一个左括号(时，我们将深度加一，并且新的深度的得分置为 0。
		// 当我们遇到一个右括号) 时，我们将当前深度的得分乘二并加到上一层的深度。
		// 这里有一种例外情况，如果遇到的是()，那么只将得分加一。

			for (char s : S) {
				if (s == '(') {
					stk.push(0);
				}
				else {
					int v = stk.top(); stk.pop();
					int w = stk.top(); stk.pop();
					stk.push(w + max(2 * v, 1));
				}
			}

		return stk.top();
	}
};