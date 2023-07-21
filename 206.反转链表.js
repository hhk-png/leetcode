/*
    反转一个单链表。

    示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
*/

// 迭代  使用prev
var reverseList = function(head) {
  let prev = null;
  let curr = head;
  while(curr) {
    let nextNode = curr.next;
    curr.next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
};

// 递归
var reverseList = function(head) {
  if(head === null || head.next === null) return head;
  let p = reverseList(head.next);
  head.next.next = head;
  head.next = null;
  return p;
};
