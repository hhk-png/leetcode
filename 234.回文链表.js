/*
    请判断一个链表是否为回文链表。

    示例 1:
    输入: 1->2
    输出: false

    示例 2:
    输入: 1->2->2->1
    输出: true
*/

/**
 * @param {ListNode} head
 * @return {boolean}
 */

// 递归
let frontPointer;
function recursivelyCheck(node) {
    if(node !== null) {
        if(!recursivelyCheck(node.next)) return false;
        if(node.val !== frontPointer.val) return false;
        frontPointer = frontPointer.next;
    }
    return true;
}
var isPalindrome = function(head) {
    frontPointer = head;
    return recursivelyCheck(head);
};


// 反转后一半链表，进行比较
var isPalindrome = function(head) {
  if(head === null || head.next === null) return head;

  let firstHalfList = endOfFirstHalf(head);
  let secondHalfList = reverseList(firstHalfList.next);

  // 相等判断
  let p1 = head;
  let p2 = secondHalfList;
  let result = true;
  while(result && p2!==null) {
    if(p1.val !== p2.val) result = false;
    p1 = p1.next;
    p2 = p2.next;
  }

  // 本题可以不再次反转
  firstHalfList.next = reverseList(secondHalfList);
  return result;
}

// 通过快慢指针，获取中间节点，
// 如果长度是奇数，中间结点属于前一部分
function endOfFirstHalf(node) {
  let slow = node;
  let fast = node.next;
  while(fast!==null && fast.next!==null) {
    fast = fast.next.next;
    slow = slow.next;
  }

  return slow;
}

function reverseList(node) {
  let prev = null;
  let curr = node;
  while(curr !== null) {
    let temp = curr.next;
    curr.next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}