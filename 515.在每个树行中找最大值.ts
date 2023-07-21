// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/submissions/

class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
  }
}


function largestValues(root: TreeNode | null): number[] {
  if (!root) {
    return []
  }
  const res: number[] = []
  const queue: TreeNode[] = [root]
  while (queue.length > 0) {
    let len: number = queue.length
    let val: number = -Number.MAX_VALUE
    while (len > 0) {
      len--
      const node: TreeNode = queue.shift()!
      val = Math.max(val, node.val)
      if (node.left) {
        queue.push(node.left)
      }
      if (node.right) {
        queue.push(node.right)
      }
    }
    res.push(val)
  }
  return res
};