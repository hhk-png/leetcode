
// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

// https://leetcode.cn/problems/linked-list-components/submissions/

// nums 是 head 的子集表示nums 的值全部在head 中

function numComponents(head: ListNode | null, nums: number[]): number {
    const numsSet: Set<number> = new Set(nums)
    let inSet: boolean = false
    let result: number = 0
    while (head) {
        if (numsSet.has(head.val)) {
            if (!inSet) {
                inSet = true
                result++
            }
        } else {
            // 遇到head 中不连续的段
            inSet = false
        }
        head = head.next
    }
    return result
};