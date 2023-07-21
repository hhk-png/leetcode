/*
	给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

	例1：
	输入: 1->2->3->4->5->NULL, k = 2
	输出: 4->5->1->2->3->NULL
	解释:
	向右旋转 1 步: 5->1->2->3->4->NULL
	向右旋转 2 步: 4->5->1->2->3->NULL

	例2：
	输入: 0->1->2->NULL, k = 4
	输出: 2->0->1->NULL
	解释:
	向右旋转 1 步: 2->0->1->NULL
	向右旋转 2 步: 1->2->0->NULL
	向右旋转 3 步: 0->1->2->NULL
	向右旋转 4 步: 2->0->1->NULL

*/



class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		// 链表为空的情况
		if (head == NULL) return head;

		// 1.计算链表长度
		int N = 1;
		ListNode* tail = head;
		while (tail->next) {
			tail = tail->next;
			N++;
		}
		// 闭环
		tail->next = head;

		// 2.切断点
		k = N - k % N -1;
		// 使head处在切断点处
		while (k) {
			head = head->next;
			k--;
		}
		tail = head;
		head = head->next; // 为了返回链表头
		// 最后一步，得到链表尾
		tail->next = NULL;

		// 3.返回
		return head;
	}
};
