// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/

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

function sumNumbers(root: TreeNode | null): number {
  let res: number = 0
  const dfs = (node: TreeNode | null, sum: number) => {
      if (!node) {
          return 
      }
      sum = sum * 10 + node.val
      if (!node.left && !node.right) {
          res += sum
      }
      dfs(node.left, sum)
      dfs(node.right, sum)
  }
  dfs(root, 0)
  return res
};