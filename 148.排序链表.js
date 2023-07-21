/*

    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

    示例 1:
    输入: 4->2->1->3
    输出: 1->2->3->4

    示例 2:
    输入: -1->5->3->4->0
    输出: -1->0->3->4->5

*/



// 先在中间截断，再合并链表
var sortList = function(head) {
  if(head === null || head.next === null) return head;


  // 使用快慢指针，分割链表
  let fast = head.next;
  let slow = head;
  while(fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }
  // 链表长度为奇数时，左边要比右边多一个
  let mid = slow.next;
  // 分割
  slow.next = null;


  let sortRight = sortList(mid);
  let sortLeft = sortList(head);
  return mergeList(sortLeft, sortRight);
};

// 链表归并排序，
function mergeList(left, right) {
  let res = new ListNode(-1);
  let head = res;
  while(left && right) {
    if(left.val < right.val) {
      res.next = left;
      res = res.next;
      left = left.next;
    } else {
      res.next = right;
      res = res.next;
      right = right.next; 
    }
  }
  res.next = left === null ? right : left; 
  return head.next;
}