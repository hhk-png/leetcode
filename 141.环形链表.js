/*

    给定一个链表，判断链表中是否有环。

    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

    输入：head = [3,2,0,-4], pos = 1
    输出：true
    解释：链表中有一个环，其尾部连接到第二个节点。
*/
/**
 * @param {ListNode} head
 * @return {boolean}
 */

// 使用hash
var hasCycle = function(head) {
  if (!head || !head.next) return false;

  const map = new Map();

  while (head !== null) {
      if (map.get(head)) {
          // map.clear() // 节省时间可以去掉
          return true;
      }
      map.set(head, true);
      head = head.next;
  }
  // map.clear()
  return false;
};

// 双指针
var hasCycle = function(head) {
  if(!head || !head.next) return false;

  let slow = head;
  let fast = head.next;

  while(slow !== fast) {
      // 只通过fast来判断是否无环
      if(fast === null || fast.next === null) {
          return false;
      }
      slow = slow.next;
      fast = fast.next.next;
  }
  return true;
};