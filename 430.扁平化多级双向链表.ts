// https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/submissions/

class LinkNode {
    val: number
    prev: LinkNode | null
    next: LinkNode | null
    child: LinkNode | null
    constructor(val?: number, prev? : LinkNode, next? : LinkNode, child? : LinkNode) {
        this.val = (val===undefined ? 0 : val);
        this.prev = (prev===undefined ? null : prev);
        this.next = (next===undefined ? null : next);
        this.child = (child===undefined ? null : child);
    }
}


function flatten(head: LinkNode | null): LinkNode | null {
  const link = (node1: LinkNode, node2: LinkNode) => {
    node1.next = node2
    node2.prev = node1
  }
  const dfs = (node: LinkNode | null) => {
    let last: LinkNode | null = null
    let cur: LinkNode | null = node
    while (cur) {
      let next = cur.next
      if (cur.child) {
        link(cur, cur.child)
        const childLast = dfs(cur.child)
        if (next) {
          link(childLast!, next)
        }
        cur.child = null
        last = childLast
      } else {
        last = cur
      }
      cur = next
    }
    return last
  }
  dfs(head)
  return head
};