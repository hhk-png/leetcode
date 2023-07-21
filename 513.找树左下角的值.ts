// https://leetcode.cn/problems/find-bottom-left-tree-value/submissions/

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

function findBottomLeftValue(root: TreeNode | null): number {
  let height = 0
  let currHeight = 0
  let currVal = root?.val || 0
  const dfs = (node: TreeNode | null, height: number) => {
    if (!node) {
      return 
    }
    dfs(node.left, height + 1)
    dfs(node.right, height + 1)
    if (height > currHeight) {
      currHeight = height
      currVal = node.val
    }
  }
  dfs(root, height)
  return currVal
};
