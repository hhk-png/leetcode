/* 
    编写一个程序，找到两个单链表相交的起始节点。

    输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
    输出：Reference of the node with value = 8
    输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，
              链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

*/


// new Set()
var getIntersectionNode = function(headA, headB) {
  if(headB === null || headA === null) return null;
  let res = new Set();

  while(headA) {
    res.add(headA);
    headA = headA.next;
  }

  while(headB) {
    if(res.has(headB)) {
      return headB;
    }
    headB = headB.next;
  }

  return null;
};


// A+B = B+A
var getIntersectionNode = function(headA, headB) {
  if (headA == null || headB == null) return null;
  let pA = headA, pB = headB;
  while (pA != pB) {
    pA = pA == null ? headB : pA.next;
    pB = pB == null ? headA : pB.next;
  }
  return pA;
};