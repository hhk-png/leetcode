// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

// 示例:
// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

var mergeKLists = function(lists) {

  while (lists.length > 1) {
    let first = lists.shift(),
        second = lists.shift();
    let c = merge(first, second);
    lists.push( c );
  }
  
  return lists.shift() || null;
};
// 合并两个有序链表
function merge(l1, l2) {
  // 链表头
  let prehead = new ListNode(-1);
  let prev = prehead;

  while (l1 !== null && l2 !== null) {
    if (l1.val <= l2.val) {
        prev.next = l1;
        l1 = l1.next;
    } else {
        prev.next = l2;
        l2 = l2.next;
    }
    prev = prev.next;
  }
  prev.next = l1 === null ? l2 : l1;
  return prehead.next;
};