﻿/*
	给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

	示例 1:
	输入: 1->1->2
	输出: 1->2
	
	示例 2:
	输入: 1->1->2->3->3
	输出: 1->2->3
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* res = head;
		ListNode* move = head;

		while (move) {
			if (move->val == res->val) {
				res->next = move->next;
			}
			else {
				res = res->next;
			}
			move = move->next;
		}

		return head;
	}
};