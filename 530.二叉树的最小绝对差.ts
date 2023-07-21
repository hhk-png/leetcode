// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/submissions/

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


function getMinimumDifference(root: TreeNode | null): number {
  let res: number = Number.MAX_VALUE
  let pre: number = -1
  const dfs = (node: TreeNode) => {
    if (!node) return
    dfs(node.left!)
    if (pre === -1) {
      pre = node.val
    } else {
      res = Math.min(res, node.val - pre)
      pre = node.val
    }
    dfs(node.right!)
  }
  dfs(root!)
  return res
};
