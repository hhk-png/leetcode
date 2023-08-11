// https://leetcode.cn/problems/same-tree/submissions/

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

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
  if (!p && !q) {
      return true
  } else if (!p || !q) {
      return false
  } else if (p.val !== q.val) {
      return false
  } else {
      return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
  }
};