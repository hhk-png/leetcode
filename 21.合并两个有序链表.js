// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

//  1.迭代
var mergeTwoLists = function(l1, l2) {
  // 链表头
  let prehead = new ListNode(-1);
  let prev = prehead;

  while (l1 !== null && l2 !== null) {
    // 在向下一个链表节点过度的时候，不需要在new一个新对象，直接将下一个节点对象赋值给当前用于过度的节点对象就好了
    if (l1.val <= l2.val) {
        prev.next = l1;
        l1 = l1.next;
    } else {
        prev.next = l2;
        l2 = l2.next;
    }
    prev = prev.next;
  }

  // exactly one of l1 and l2 can be non-null at this point, so connect
  // the non-null list to the end of the merged list.
  // 处理剩下的最后一个节点，最后一个节点的next是null。
  prev.next = l1 === null ? l2 : l1;

  return prehead.next;
};

// 2.递归
var mergeTwoLists = function(l1, l2) {
  if (l1 == null) {
    return l2;
  }
  else if (l2 == null) {
    return l1;
  }
  else if (l1.val < l2.val) {
    l1.next = mergeTwoLists(l1.next, l2);
    return l1;
  }
  else {
    l2.next = mergeTwoLists(l1, l2.next);
    return l2;
  }
}