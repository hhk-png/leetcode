/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]

*/
// 迭代
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* result = new ListNode(0);
		result->next = head;
		ListNode* temp = result;

		while (temp->next && temp->next->next) {
			ListNode* node1 = temp->next;
			ListNode* node2 = temp->next->next;
			temp->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			temp = node1;
		}

		return result->next;
	}
};


// 递归
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}

		ListNode* newHead = head->next;
		head->next = swapPairs(newHead->next);
		newHead->next = head;

		return newHead;
	}
};
