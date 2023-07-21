// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：
//    给定一个链表: 1->2->3->4->5, 和 n = 2.
//    当删除了倒数第二个节点后，链表变为 1->2->3->5.

// 给定的 n 保证是有效的。

var removeNthFromEnd = function(head, n) {

  let first = head;
  let second = head;

  // 向前走n个位置，使 first 和 second 之间保持n个长度
  for (let i = 0; i < n; i++) {
      first = first.next;
  }

  // 当n === length时，返回head.next
  if(!first) {
      return head.next;
  }

  // 在同时向前走
  while (first.next != null) {
      first = first.next;
      second = second.next;
  }

  // 最后一步处理，直接插入
  second.next = second.next.next;
  return head;
};