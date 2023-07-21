// https://leetcode.cn/problems/find-mode-in-binary-search-tree/submissions/


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


function findMode(root: TreeNode | null): number[] {
  let base: number = 0
  let count: number = 0
  let maxCount: number = 0
  let res: number[] = []
  const update = (val: number) => {
    if (base === val) {
      count++
    } else {
      base = val
      count = 1
    }

    if (count === maxCount) {
      res.push(val)
    }
    if (count > maxCount) {
      maxCount = count
      res = [val]
    }
  }
  const dfs = (node: TreeNode) => {
    if (!node) return
    dfs(node.left!)
    update(node.val)
    dfs(node.right!)
  }
  dfs(root!)
  return res
};