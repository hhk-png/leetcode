// https://leetcode.cn/problems/print-binary-tree/description/

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function printTree(root: TreeNode | null): string[][] {
  const calcDepth = (root: TreeNode | null) => {
      let height: number = 0
      if (root.left) {
          height = Math.max(height, calcDepth(root.left) + 1)
      }
      if (root.right) {
          height = Math.max(height, calcDepth(root.right) + 1)
      }
      return height
  }

  const dfs = (res: string[][], node: TreeNode | null, row: number, col: number, height: number) => {
      res[row][col] = node.val + ''
      if (node.left) {
          dfs(res, node.left, row + 1, col - (1 << (height - row - 1)), height)
      }
      if (node.right) {
          dfs(res, node.right, row + 1, col + (1 << (height - row - 1)), height);
      }
  }
  const height = calcDepth(root)
  const m = height + 1
  const n = (1 << (height + 1)) - 1
  const res = new Array(m).fill(0).map(() => new Array(n).fill(''));
  dfs(res, root, 0, Math.floor((n - 1) / 2), height);
  return res;
};
