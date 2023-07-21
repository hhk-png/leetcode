/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */

// 后驱节点
let successor = null;
// 反转第m~n个结点
var reverseBetween = function(head, m, n) {
    if(m === 1) {
        return reverseN(head, n);
    }
    head.next = reverseBetween(head.next, m - 1, n - 1);
    return head;
};

// 反转第1~n个结点
var reverseN = function(head, n) {
    if(n === 1) {
        // 记录第n+1个结点，并且只有当n===1的时候才会改变successor
        successor = head.next;
        // 连边反转后的头节点，也只有n===1的时候才会被改变
        return head;
    }
    // 这里的last也就是第n个结点，反转后的head
    let last = reverseN(head.next, n - 1);
    // 链表反转基本操作
    head.next.next = head;
    head.next = successor; // 指向第n+1个结点
    // 最后返回头节点
    return last;
}