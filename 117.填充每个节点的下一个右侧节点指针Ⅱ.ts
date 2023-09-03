// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/

class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  next: TreeNode | null
  constructor(val?: number, left?: TreeNode, right?: TreeNode, next?: TreeNode) {
    this.val = val === undefined ? -1 : val
    this.left = left === undefined ? null : left
    this.right = right === undefined ? null : right
    this.next = next === undefined ? null : next
  }
}


function connect(root: TreeNode | null): TreeNode | null {
    if (!root) {
        return root
    }
    const queue: TreeNode[] = []
    queue.push(root)
    while (queue.length) {
        const n: number = queue.length
        let prev: TreeNode | null = null

        for (let i = 0; i < n; i++) {
            const node: TreeNode = queue.shift()!

            if (prev) {
                prev.next = node
            }

            prev = node

            if (node.left) {
                queue.push(node.left)
            }
            if (node.right) {
                queue.push(node.right)
            }
        }
    }

    return root
};
