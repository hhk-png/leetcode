// https://leetcode.cn/problems/add-two-numbers-ii/submissions/

class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const stk1: number[] = []
    const stk2: number[] = []
    while (l1) {
        stk1.push(l1.val)
        l1 = l1.next
    }
    while (l2) {
        stk2.push(l2.val)
        l2 = l2.next
    }
    let res: ListNode = new ListNode(-1)
    let carry: number = 0
    while (stk1.length || stk2.length || carry !== 0) {
        const val1: number = stk1.length ? stk1.pop()! : 0
        const val2: number = stk2.length ? stk2.pop()! : 0
        // console.log(val1, val2)
        const val: number = val1 + val2 + carry
        const currVal: number = val % 10
        carry = Math.floor(val / 10)
        const currNode: ListNode = new ListNode(currVal)
        currNode.next = res.next
        res.next = currNode
    }
    return res.next
};

