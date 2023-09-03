// https://leetcode.cn/problems/path-sum-ii/submissions/

class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

function pathSum(root: TreeNode | null, targetSum: number): number[][] {
  const res: number[][] = []
  const path: number[] = []
  const dfs = (node: TreeNode | null, targetSum: number) => {
      if (!node) {
          return;
      }
      path.push(node.val)
      targetSum -= node.val
      if (!node.left && !node.right && targetSum === 0) {
          res.push(path.slice())
      }
      dfs(node.left, targetSum)
      dfs(node.right, targetSum)
      path.pop()
  }
  dfs(root, targetSum)
  return res
};