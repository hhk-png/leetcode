// https://leetcode.cn/problems/binary-tree-tilt/submissions/

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

function findTilt(root: TreeNode | null): number {
  let ans = 0;

  const dfs = (node: TreeNode | null) => {
    if (!node) {
      return 0;
    }
    const sumLeft = dfs(node.left);
    const sumRight = dfs(node.right);
    ans += Math.abs(sumLeft - sumRight);
    return sumLeft + sumRight + node.val;
  }

  dfs(root);
  return ans;

};