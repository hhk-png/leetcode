/*
	反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

	说明:
	1 ≤ m ≤ n ≤ 链表长度。

	示例:
	输入: 1->2->3->4->5->NULL, m = 2, n = 4
	输出: 1->4->3->2->5->NULL
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* pre = dummyNode;
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		ListNode* next;
		for (int i = 0; i < right - left; i++) {
			next = cur->next;
			cur->next = next->next;
			next->next = pre->next;
			pre->next = next;
		}
		return dummyNode->next;
	}
};
