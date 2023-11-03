// https://leetcode.cn/problems/add-one-row-to-tree/description/

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

function addOneRow(root: TreeNode | null, val: number, depth: number): TreeNode | null {
  if (depth === 1) {
      return new TreeNode(val, root, null)
  }
  let currLevel: TreeNode[] = []
  currLevel.push(root!)
  for (let i = 1; i < depth - 1; i++) {
      let n: number = currLevel.length
      for (let i = 0; i < n; i++) {
          let node: TreeNode = currLevel.shift()!
          if (node.left) {
              currLevel.push(node.left)
          }
          if (node.right) {
              currLevel.push(node.right)
          }
      }
  }
  for (const node of currLevel) {
      node.left = new TreeNode(val, node.left, null)
      node.right = new TreeNode(val, null, node.right)
  }
  return root
};

