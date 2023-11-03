// https://leetcode.cn/problems/subtree-of-another-tree/description/

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

function isSubtree(root: TreeNode | null, subRoot: TreeNode | null): boolean {
  // 判断两棵树是否相同
  const isSameTree = (node1: TreeNode | null, node2: TreeNode | null) => {
      if (!node1 && !node2) {
          return true
      }
      if ((node1 && !node2) || (!node1 && node2) || (node1!.val !== node2!.val)) {
          return false
      }
      return isSameTree(node1!.left, node2!.left) && isSameTree(node1!.right, node2!.right)
  }
  // 遍历 root 
  const dfs = (node: TreeNode | null) => {
      if (!node) {
          return false
      }
      return isSameTree(node, subRoot) || dfs(node.left) || dfs(node.right)
  }

  return dfs(root)
};
