
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

class Solution {
    listArr: number[]
    constructor(head: ListNode | null) {
        if (!head) {
            return
        }
        this.listArr = []
        while (head) {
            this.listArr.push(head.val)
            head = head.next
        }
    }

    getRandom(): number {
        const n: number = this.listArr.length
        if (!n) return -1
        return this.listArr[Math.floor(Math.random() * n)]
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(head)
 * var param_1 = obj.getRandom()
 */