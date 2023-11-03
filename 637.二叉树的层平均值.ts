// https://leetcode.cn/problems/average-of-levels-in-binary-tree/submissions/

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

function averageOfLevels(root: TreeNode | null): number[] {
  if (!root) {
    return []
  }
  const queue: TreeNode[] = []
  queue.push(root)
  const res: number[] = []

  while (queue.length) {
    let n: number = queue.length
    let sum: number = 0;
    for (let i = 0; i < n; i++) {
      const node = queue.shift()
      sum += node!.val
      if (node!.left) {
        queue.push(node!.left)
      }
      if (node!.right) {
        queue.push(node!.right)
      }
    }
    res.push(sum / n)
  }
  return res
};
