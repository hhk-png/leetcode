// https://leetcode.cn/problems/sum-of-left-leaves/submissions/

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



function sumOfLeftLeaves(root: TreeNode | null): number {
  return !root ? 0 : dfs(root)
};

function dfs(node: TreeNode): number {
  let ans = 0
  if (node.left) {
    ans += isLeafNode(node.left) ? node.left.val : dfs(node.left)
  }
  if (node.right) {
    ans += dfs(node.right)
  }
  return ans
}

function isLeafNode(node: TreeNode): boolean {
  return !node.left && !node.right
}
