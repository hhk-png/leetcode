/*
	给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

	删除完毕后，请你返回最终结果链表的头节点。

 

	你可以返回任何满足题目要求的答案。

	（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

	示例 1：
	输入：head = [1,2,-3,3,1]
	输出：[3,1]
	提示：答案 [1,2,1] 也是正确的。

	示例 2：
	输入：head = [1,2,3,-3,4]
	输出：[1,2,4]

	示例 3：
	输入：head = [1,2,3,-3,-2]
	输出：[1]

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;

		// sum -> ListNode*
		map<int, ListNode*> map;
		int sum = 0;
		// 如果同一个和出现在多次那么后面的会覆盖前面的
		for (ListNode* d = dummyNode; d != NULL; d = d->next) {
			sum += d->val;
			map[sum] = d;
		}

		sum = 0;
		// 若当前结点处num出现在了下一处，则说明这两个结点之间的值为0
		//	删除
		for (ListNode* d = dummyNode; d != NULL; d = d->next) {
			sum += d->val;
			d->next = map[sum]->next;
		}

		return dummyNode->next;
	}
};