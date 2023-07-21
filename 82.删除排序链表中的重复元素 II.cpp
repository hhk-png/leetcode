/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:
输入: 1->1->1->2->3
输出: 2->3
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* result = new ListNode(0);
		result->next = head;
		// 使用哨兵结点
		ListNode* a = result;
		ListNode* b = head->next;

		while (b) {
			// 两者相等，同时向后移一位
			if (a->next->val != b->val) {
				a = a->next;
				b = b->next;
			} else {
				// 找到第一个不相等的结点
				while (b && b->val == a->next->val) {
					b = b->next;
				}

				// 直接改变哨兵的指针
				a->next = b;

				// 处理b为null的情况
				b = b ? b->next : NULL;
			}
		}

		return result->next;
	}
};