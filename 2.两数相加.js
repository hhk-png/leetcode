/*
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
*/

// 本题的主要是链表各个位置元素的相加
var addTwoNumbers = function (l1, l2) {
  let result = new ListNode(null);
  let nextEst = result;
  // 保存两数相加之后在当前位置的数
  let val = 0;
  // 进位
  let params = 0;
  // l1和l2可能不同时为空，所以需要共同进行l1和l2的非空判断
  while (l1 != null || l2 != null) {
    // 取值
    let x = l1 != null ? l1.val : 0;
    let y = l2 != null ? l2.val : 0;

    // 相加,处理
    val = (x + y + params) % 10;
    params = Math.floor((x + y + params) / 10);

    // 下一个链表位置
    nextEst.next = new ListNode(val);
    nextEst = nextEst.next;

    // 给定链表的下一个元素
    if (l1 != null) l1 = l1.next;
    if (l2 != null) l2 = l2.next;
  }

  // 最后进位的处理
  if (params) {
    nextEst.next = new ListNode(params);
  }

  return result.next;
};

/* c++
class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          // 如果初始化为nullptr，会报错
          ListNode *result = new ListNode(0);
          ListNode *nextNode = result;
          
          int val = 0;
          int param = 0;
  
          while (l1 || l2) {
              int x = l1 ? l1->val : 0;
              int y = l2 ? l2->val : 0;
  
              val = (x + y + param) % 10;
              param = (x + y + param) / 10;
  
              nextNode->next = new ListNode(val);
              nextNode = nextNode->next;
  
              if (l1) l1 = l1->next;
              if (l2) l2 = l2->next;
          }
          if (param) {
              nextNode->next = new ListNode(param);
          }
  
          return result->next;
      }
  };
*/
